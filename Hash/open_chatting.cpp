#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

const int MAX = 30;

// delim를 기준으로 문자열 잘라서 vector로 반환하는 함수
vector<string> split(string input, char delim) {

	vector<string> result;
	string output = "";

	for (int i = 0; i < input.size(); i++) {

		if (input[i] == delim) { // input[oii]는 char니까 == 가능
			result.push_back(output);
			output = "";
		}
		else {
			output += input[i];
		}
	}

	// output.compare(string) => 다르면 1 / 같으면 0 / output이 "" 인데 string이 ""이 아니면 -1
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

	// 특정 uid와 닉네임 mapping list 만들기
	for (auto log : record) {

		// log가 Leave면 굳이 mapping list 만들 때 신경 쓸 필요가 없다
		if (log[0] == 'L') { continue; }

		vector<string> tmp = split(log, ' ');

		names[tmp[1]] = tmp[2];
	}

	for (auto log : record) {

		if (log[0] == 'C') { continue; }

		vector<string> tmp = split(log, ' ');

		string comment = names[tmp[1]] + "님이 ";
		
		if (!tmp[0].compare("Enter")) {
			comment += "들어왔습니다.";
		}
		else if (!tmp[0].compare("Leave")) {
			comment += "나갔습니다.";
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