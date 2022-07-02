#include <iostream>
using namespace std;

// n개의 원판을 now번 장대에서 move번 장대로 옮기기
void hanoi(int n, int now, int move) {
	if (n <= 1) {
		cout << now << " " << move << "\n";
		return;
	}
	
	int mid = 1;
	if (mid == now) { mid = move == 2 ? 3 : 2; }
	if (mid == move) { mid = now == 2 ? 3 : 2; }

	// 전반부 이동
	hanoi(n - 1, now, mid);

	// 가장 큰 판 이동
	cout << now << " " << move << "\n";

	// 후반부 이동
	hanoi(n - 1, mid, move);
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);

	int N, counter[22] = { 0 };
	cin >> N;

	counter[0] = 0;
	counter[1] = 1;
	for (int i = 2; i <= N; i++) {
		counter[i] = counter[i - 1] * 2 + 1;
	}

	cout << counter[N] << "\n";

	hanoi(N, 1, 3);
}