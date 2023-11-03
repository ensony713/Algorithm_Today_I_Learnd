#include <iostream>
#include <cmath>
using namespace std;

// row, col = ���� ��и��� 0, 0
// now = ���� ��и��� �� ��
int divide_and_conquer(int now, int r, int c, int row, int col, int cnt) {

	if (r < row || c < col || r > row + now || c > col + now) {
		return 0;
	}
	if (r == row && c == col) {
		return cnt;
	}

	int center_row = row + (now / 2), center_col = col + (now / 2);
	int mid = now / 2, max = 0, tmp;
	// hum..
	tmp = divide_and_conquer(mid, r, c, row, col, cnt); // 1��и�
	max = tmp != 0 ? tmp : max;

	tmp = divide_and_conquer(mid, r, c, row, center_col, cnt + (mid * mid)); // 2��и�
	max = tmp != 0 ? tmp : max;

	tmp = divide_and_conquer(mid, r, c, center_row, col, cnt + (mid * mid) * 2); // 3��и�
	max = tmp != 0 ? tmp : max;

	tmp = divide_and_conquer(mid, r, c, center_row, center_col, cnt + (mid * mid) * 3); // 4��и�
	max = tmp != 0 ? tmp : max;

	return max;
}

int main(int argc, char** argv) {
	int n, r, c;

	cin >> n >> r >> c;
	n = pow(2, n);

	cout << divide_and_conquer(n, r, c, 0, 0, 0) << '\n';

	return 0;
}