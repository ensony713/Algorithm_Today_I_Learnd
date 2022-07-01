#include <iostream>
using namespace std;

bool condition(int N, int n, int i, int j) {
	if ((i / (N / n)) % 3 == 1 && (j / (N / n) % 3 == 1)) {
		return true;
	}

	if ((n / 3) >= 1) { return condition(N, n / 3, i, j); }
	else { return false; }
}

void stars(int N, int i, int j) {
	if (j == N) {
		cout << "\n";
		stars(N, i + 1, 0);
		return;
	}
	if (i == N) {
		return;
	}

	if (condition(N, N, i, j)) { cout << " "; }
	else { cout << "*"; }
	stars(N, i, j + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);

	int N;
	cin >> N;
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (condition(N, N, i, j)) {
				cout << " ";
			}
			else {
				cout << "*";
			}
		}
		cout << "\n";
	}*/

	stars(N, 0, 0);

	return 0;
}