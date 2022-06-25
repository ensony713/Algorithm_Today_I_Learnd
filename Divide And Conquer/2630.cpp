#include <iostream>
using namespace std;

int N, paper[150][150] = { 0 }, sum_blue = 0, sum_white = 0;

bool color_check(int n, int x, int y, int & color) {
	int blue = 0, white = 0;
	for (int i = x; i < n + x; i++) {
		for (int j = y; j < n + y; j++) {
			if (paper[i][j])
				blue++;
			else
				white++;
		}
	}

	if (blue == n * n) { // 전부 파란색
		color = 1;
		return true;
	}
	else if (white == n * n) { // 전부 하얀색
		color = 0;
		return true;
	}
	else // 섞여있는 경우
		return false;
}

void division(int n, int x, int y) {
	int color, size = 0;
	bool check;

	if (n == 1 && paper[x][y]) {
		sum_blue++;
		return;
	}
	else if (n == 1 && !paper[x][y]) {
		sum_white++;
		return;
	}

	check = color_check(n, x, y, color);
	if (check && color) // 전부 파란색일 경우 파란 종이 수 +1
		sum_blue++;
	else if (check && !color) // 전부 하얀색일 경우 하얀 종이 수 +1
		sum_white++;
	else { // 섞여있을 경우 재분할
		size = n / 2;
		division(size, x, y); // 좌측 위
		division(size, x + size, y); // 우측 위
		division(size, x, y + size); // 좌측 아래
		division(size, x + size, y + size); // 우측 아래
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) cin >> paper[i][j];

	division(N, 0, 0);

	cout << sum_white << "\n" << sum_blue << "\n";
	return 0;
}