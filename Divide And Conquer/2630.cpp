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

	if (blue == n * n) { // ���� �Ķ���
		color = 1;
		return true;
	}
	else if (white == n * n) { // ���� �Ͼ��
		color = 0;
		return true;
	}
	else // �����ִ� ���
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
	if (check && color) // ���� �Ķ����� ��� �Ķ� ���� �� +1
		sum_blue++;
	else if (check && !color) // ���� �Ͼ���� ��� �Ͼ� ���� �� +1
		sum_white++;
	else { // �������� ��� �����
		size = n / 2;
		division(size, x, y); // ���� ��
		division(size, x + size, y); // ���� ��
		division(size, x, y + size); // ���� �Ʒ�
		division(size, x + size, y + size); // ���� �Ʒ�
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