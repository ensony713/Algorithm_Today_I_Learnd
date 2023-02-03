#include <iostream>
#define MAX 100
using namespace std;

int main(int argc, char* argv[]) {
	int matrix[MAX][MAX] = { 0 };
	int n, m, tmp;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			matrix[i][j] += tmp;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j];
			if (j != m - 1) { cout << ' '; }
		}
		cout << '\n';
	}

	return 0;
}