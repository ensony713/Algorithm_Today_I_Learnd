#include <iostream>
#include <algorithm>
#include <limits.h>
#define MAX 500
using namespace std;

typedef struct matrix {
	int row, col;
};

long cache[MAX][MAX] = {0};
matrix input[MAX];

long dp(int n, int m) {

	if (n == m) {
		return 0;
	}

	if (cache[n][m] != 0) {
		return cache[n][m];
	}

	cache[n][m] = INT_MAX;
	for (int i = n; i < m; i++) {

		cache[n][m] = min(cache[n][m], 
			dp(n, i) + dp(i + 1, m) + input[n].row * input[i + 1].row * input[m].col);
	}

	return cache[n][m];
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, r, c;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input[i].row >> input[i].col;
	}
	
	cout << dp(0, n - 1) << '\n';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << cache[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}