#include <iostream>
using namespace std;

int main() {
	int t, k, n;
	unsigned int room[16][16] = { 0 };
	cin >> t;

	for (int i = 0; i <= 15; i++) {
		room[0][i] = i;
	}

	for (int i = 1; i < 15; i++) { // Ãþ¼ö
		for (int j = 1; j < 15; j++) { // È£¼ö
			for (int k = 1; k <= j; k++) {
				room[i][j] += room[i - 1][k];
			}
		}
	}

	while (t-- > 0) {
		cin >> k >> n;
		cout << room[k][n] << '\n';
	}
	return 0;
}