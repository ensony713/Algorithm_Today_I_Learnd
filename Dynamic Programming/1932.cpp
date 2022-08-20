#include <iostream>
using namespace std;

int tri[500][500] = { 0 };

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, maxi = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				tri[i][j] += tri[i - 1][j];
			}
			else if (j == i) {
				tri[i][j] += tri[i - 1][j - 1];
			}
			else {
				tri[i][j] = tri[i - 1][j - 1] > tri[i - 1][j] ?
					tri[i][j] + tri[i - 1][j - 1] : tri[i][j] + tri[i - 1][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		maxi = maxi > tri[n - 1][i] ? maxi : tri[n - 1][i];
	}

	cout << maxi;
	return 0;
}