#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

string solution(vector<string>& participant, vector<string>& completion) {

	string answer = "";
	unordered_map<string, int> map;

	// 참가자 이름을 key, 해당 이름을 가진 사람 수를 value
	for (auto p : participant) {

		int cnt = map.count(p);

		if (cnt < 1) {
			map.insert({ p, 1 });
			// 이미 같은 key가 있을 경우 insert는 무시됨
		}
		else {
			map.at(p)++;
			// at은 참조를 반환해서 이렇게 써도 정상 동작한다
		}
	}

	// 완주자 명단에 있는 이름들을 -1 함
	for (auto c : completion) {

		if (--map.at(c) != 0) {
			answer = c;
		} else {
			// 명수가 0이면 지움
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

	// vector는 무작위 요소에 접근할 때 O(1)시간이 걸린대 -> 연속적인 배열 형태로 저장되어있나보다 T value[n] 이런식인듯
	vector<string> participant, completion;
	string input;
	int n = 0;

	cin >> n;

	// 참가자 입력받기
	for (int i = 0; i < n; i++) {
		cin >> input;
		participant.push_back(input);
	}

	// 완주자 입력받기
	for (int i = 0; i < n - 1; i++) {
		cin >> input;
		completion.push_back(input);
	}

	cout << solution(participant, completion) << '\n';

	return 0;
}