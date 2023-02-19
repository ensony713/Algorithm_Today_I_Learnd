#include <iostream>
#define MAX 100
using namespace std;

char board[MAX][MAX];
int black[MAX][MAX] = { 0 }, white[MAX][MAX] = { 0 };
// black[i][j]와 white[i][j]는 [0][0]이 각각 B, W일 때 [0][0]부터 [i][j]까지
// 바꿔야 하는 자리의 개수를 모두 합한 것

bool is_ok_onB(int n, int m, int x, int y) {

	if (((x + y) % 2 == 0) && board[x][y] == 'B') {
		return true;
	}

	if (((x + y) % 2 == 1) && board[x][y] == 'W') {
		return true;
	}

	return false;
}

bool is_ok_onW(int n, int m, int x, int y) {

	if (((x + y) % 2 == 0) && board[x][y] == 'W') {
		return true;
	}

	if (((x + y) % 2 == 1) && board[x][y] == 'B') {
		return true;
	}

	return false;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int n, m, k, x, y, mini = MAX * MAX, result;
	string input;

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> input;

		for (int j = 0; j < input.size(); j++) {
			board[i][j] = input[j];

			if (is_ok_onB(n, m, i, j)) {
				black[i][j] = 1;
			}
			if (is_ok_onW(n, m, i, j)) {
				white[i][j] = 1;
			}

			if (i != 0) {
				black[i][j] += black[i - 1][j];
				white[i][j] += white[i - 1][j];
			}
			if (j != 0) {
				black[i][j] += black[i][j - 1];
				white[i][j] += white[i][j - 1];
			}
			if (i != 0 && j != 0) {
				black[i][j] -= black[i - 1][j - 1];
				white[i][j] -= white[i - 1][j - 1];
			}
		}
	}

	for (int i = k - 1; i < n; i++) {
		for (int j = k - 1; j < m; j++) {

			x = i - k;
			y = j - k;

			result = black[i][j];

			if (x >= 0) {
				result -= black[x][j];
			}
			if (y >= 0) {
				result -= black[i][y];
			}
			if (x >= 0 && y >= 0) {
				result += black[x][y];
			}

			mini = mini > result ? result : mini;

			result = white[i][j];

			if (x >= 0) {
				result -= white[x][j];
			}
			if (y >= 0) {
				result -= white[i][y];
			}
			if (x >= 0 && y >= 0) {
				result += white[x][y];
			}

			mini = mini > result ? result : mini;
		}
	}

	cout << mini;
	return 0;
}