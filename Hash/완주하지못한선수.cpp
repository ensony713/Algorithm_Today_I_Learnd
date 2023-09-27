#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

string solution(vector<string>& participant, vector<string>& completion) {

	string answer = "";
	unordered_map<string, int> map;

	// ������ �̸��� key, �ش� �̸��� ���� ��� ���� value
	for (auto p : participant) {

		int cnt = map.count(p);

		if (cnt < 1) {
			map.insert({ p, 1 });
			// �̹� ���� key�� ���� ��� insert�� ���õ�
		}
		else {
			map.at(p)++;
			// at�� ������ ��ȯ�ؼ� �̷��� �ᵵ ���� �����Ѵ�
		}
	}

	// ������ ��ܿ� �ִ� �̸����� -1 ��
	for (auto c : completion) {

		if (--map.at(c) != 0) {
			answer = c;
		} else {
			// ����� 0�̸� ����
			map.erase(c);
		}
	}

	cout << '\n';
	for (auto i : map) {
		answer = i.first;
		cout << i.first << ", " << i.second << '\n';
	}

	return answer;
}

int main(int argc, char** argv) {

	// vector�� ������ ��ҿ� ������ �� O(1)�ð��� �ɸ��� -> �������� �迭 ���·� ����Ǿ��ֳ����� T value[n] �̷����ε�
	vector<string> participant, completion;
	string input;
	int n = 0;

	cin >> n;

	// ������ �Է¹ޱ�
	for (int i = 0; i < n; i++) {
		cin >> input;
		participant.push_back(input);
	}

	// ������ �Է¹ޱ�
	for (int i = 0; i < n - 1; i++) {
		cin >> input;
		completion.push_back(input);
	}

	cout << solution(participant, completion) << '\n';

	return 0;
}