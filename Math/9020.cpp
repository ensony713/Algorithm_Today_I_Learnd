#include <iostream>
using namespace std;

bool is_prime(int n) {
	if (n == 1) return false;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) { return false; }
	}
	return true;
}

int main(int argc, char* argv[]) {
	int n, t, tmp;
	cin >> t;

	for (; t > 0; t--) {
		cin >> n;

		for (int i = n / 2; i > 0; i--) {
			tmp = n - i;
			if (is_prime(i) && is_prime(tmp)) {
				cout << i << " " << tmp << '\n';
				break;
			}
		}
	}

	return 0;
}