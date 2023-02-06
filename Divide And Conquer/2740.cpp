#include <iostream>
#define MAX 10
using namespace std;

int main(int argc, char* argv) {
	int n, m, k, input;
	int matrixA[MAX][MAX] = { 0 }, matrixB[MAX][MAX] = { 0 };

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrixA[i][j];
		}
	}

	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> matrixB[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			input = 0;
			for (int l = 0; l < m; l++) {
				input += matrixA[i][l] * matrixB[l][j];
			}
			cout << input;
			if (j != k - 1) { cout << ' '; }
		}
		cout << '\n';
	}

	return 0;
}