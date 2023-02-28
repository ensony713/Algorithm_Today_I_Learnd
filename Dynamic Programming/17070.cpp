#include <iostream>
#define MAX 20
using namespace std;

int house[MAX][MAX] = { 0 };

bool diagonal(int x, int y, int n, char position) {

	if (x + 1 > n || y + 1 > n) {
		return false;
	}
	if (house[x + 1][y] == 1 || house[x][y + 1] == 1 || house[x + 1][y + 1] == 1) {
		return false;
	}
	return true;
}

bool horizon(int x, int y, int n, char position) {

	if (position == 'V') {
		return false;
	}
	if (y + 1 > n) {
		return false;
	}
	if (house[x][y + 1] == 1) {
		return false;
	}
	return true;
}

bool vertical(int x, int y, int n, char position) {

	if (position == 'H') {
		return false;
	}
	if (x + 1 > n) {
		return false;
	}
	if (house[x + 1][y] == 1) {
		return false;
	}
	return true;
}

int dp(int x, int y, int n, char p) {
	if (x > n || y > n) {
		return 0;
	}

	if (x == n && y == n) {
		return 1;
	}

	int result = 0;
	if (diagonal(x, y, n, p)) {
		result += dp(x + 1, y + 1, n, 'D');
	}

	if (horizon(x, y, n, p)) {
		result += dp(x, y + 1, n, 'H');
	}

	if (vertical(x, y, n, p)) {
		result += dp(x + 1, y, n, 'V');
	}
	cout << '\n';

	return result;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> house[i][j];
		}
	}

	cout << dp(1, 2, n, 'H');

	return 0;
}