#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int n = 101; // 최대 카드 장수

// 1번 상자 = start에서 시작
// 2번 상자 = seconde에서 시작
int calculate_point(vector<int>& cards, int start, int seconde) {

	bool visite[n] = { 0 };

	int idx = start;
	int cnt_1 = 0;
	int cnt_2 = 0;

	// 1번 박스의 장수 구하기
	while (true) {
		
		if (!visite[idx]) {
			visite[idx] = true;
			idx = cards[idx] - 1; // 실제 들어있는 카드 번호는 1부터 시작하므로 -1 해줘야 cards vector의 index가 됨
			cnt_1++;
		}
		else {
			break;
		}
	}

	if (cnt_1 == cards.size()) {
		cnt_1 = 0;
	}
	
	// 2번 박스의 장수 구하기
	idx = seconde;
	while (true) {

		if (!visite[idx]) {
			visite[idx] = true;
			idx = cards[idx] - 1;
			cnt_2++;
		}
		else {
			break;
		}
	}

	return cnt_1 * cnt_2;
}

int solution(vector<int>& cards) {
	int answer = 0;

	for (int i = 0; i < cards.size(); i++) {
		for (int j = 0; j < cards.size(); j++) {

			if (i != j) { // 시작 지점이 같으면 0점이라 의미 없으므로 수행 X
				int tmp = calculate_point(cards, i, j);
				answer = tmp > answer ? tmp : answer;
			}
		}
	}

	return answer;
}

int main(int argc, char** argv) {

	int n, input;
	vector<int> cards;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		cards.push_back(input);
	}

	cout << solution(cards) << '\n';

	return 0;
}