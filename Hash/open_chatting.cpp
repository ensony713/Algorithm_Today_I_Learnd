#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

const int MAX = 30;

// delim�� �������� ���ڿ� �߶� vector�� ��ȯ�ϴ� �Լ�
vector<string> split(string input, char delim) {

	vector<string> result;
	string output = "";

	for (int i = 0; i < input.size(); i++) {

		if (input[i] == delim) { // input[oii]�� char�ϱ� == ����
			result.push_back(output);
			output = "";
		}
		else {
			output += input[i];
		}
	}

	// output.compare(string) => �ٸ��� 1 / ������ 0 / output�� "" �ε� string�� ""�� �ƴϸ� -1
	//cout << output << ":" << output.compare("") << '\n';

	if (output.compare("")) {
		result.push_back(output);
	}

	return result;
}

vector<string> solution(vector<string>& record) {
	vector<string> answer;

	// map?
	unordered_map<string, string> names;

	// Ư�� uid�� �г��� mapping list �����
	for (auto log : record) {

		// log�� Leave�� ���� mapping list ���� �� �Ű� �� �ʿ䰡 ����
		if (log[0] == 'L') { continue; }

		vector<string> tmp = split(log, ' ');

		names[tmp[1]] = tmp[2];
	}

	for (auto log : record) {

		if (log[0] == 'C') { continue; }

		vector<string> tmp = split(log, ' ');

		string comment = names[tmp[1]] + "���� ";
		
		if (!tmp[0].compare("Enter")) {
			comment += "���Խ��ϴ�.";
		}
		else if (!tmp[0].compare("Leave")) {
			comment += "�������ϴ�.";
		}

		answer.push_back(comment);
	}

	return answer;
}

int main(int argc, char** argv) {

	vector<string> recode;
	int n;
	string input;

	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		getline(cin, input);
		recode.push_back(input);
	}

	/*getline(cin, input);
	
	recode = split(input, ' ');
	for (int i = 0; i < recode.size(); i++) {
		cout << i << ") " << recode[i] << '\n';
	}*/

	recode = solution(recode);
	for (auto i : recode) {
		cout << i << '\n';
	}

	return 0;
}