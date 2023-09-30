#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int n = 101; // �ִ� ī�� ���

// 1�� ���� = start���� ����
// 2�� ���� = seconde���� ����
int calculate_point(vector<int>& cards, int start, int seconde) {

	bool visite[n] = { 0 };

	int idx = start;
	int cnt_1 = 0;
	int cnt_2 = 0;

	// 1�� �ڽ��� ��� ���ϱ�
	while (true) {
		
		if (!visite[idx]) {
			visite[idx] = true;
			idx = cards[idx] - 1; // ���� ����ִ� ī�� ��ȣ�� 1���� �����ϹǷ� -1 ����� cards vector�� index�� ��
			cnt_1++;
		}
		else {
			break;
		}
	}

	if (cnt_1 == cards.size()) {
		cnt_1 = 0;
	}
	
	// 2�� �ڽ��� ��� ���ϱ�
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

			if (i != j) { // ���� ������ ������ 0���̶� �ǹ� �����Ƿ� ���� X
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