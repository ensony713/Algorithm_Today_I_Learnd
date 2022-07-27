#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	bool prime[250000] = { 0 };
	int n = 1, cnt = 0;

	while (true) {
		prime[1] = true;

		cin >> n;
		if (n == 0) return 0;

		cnt = 0;

		for (int i = 2; i <= 2 * n; i++) {
			for (int j = 2; j * i <= 2 * n; j++) {
				prime[j * i] = true;
			}

			if (!prime[i] && i > n) cnt++;
		}

		cout << cnt << '\n';

		for (int i = 0; i <= 2 * n; i++) {
			prime[i] = false;
		}
	}
	return 0;
}