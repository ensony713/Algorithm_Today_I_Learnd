#include <iostream>
using namespace std;

int main() {

	int n, k, A[11] = { 0 }, result = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		if (k >= A[i]) {
			result += k / A[i];
			k = k % A[i];
		}
	}

	cout << result;
	return 0;
}