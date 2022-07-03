#include <iostream>
#define MAX 102
using namespace std;

int main() {
	int n, m, card[MAX], result = 0, tmp;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				tmp = card[i] + card[j] + card[k];
				if (tmp == m) {
					result = tmp;
					break;
				}
				if (tmp < m && tmp > result) result = tmp;
			}
		}
	}
	
	cout << result;
	return 0;
}