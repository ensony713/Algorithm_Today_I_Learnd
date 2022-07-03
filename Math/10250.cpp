#include <iostream>
using namespace std;

int main() {

	int h, m, n, c = 0, T;

	cin >> T;

	while (1) {
		cin >> h >> m >> n;
		c = 0;

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= h; j++) {
				c++;
				if (c == n) {
					cout << j;
					if (i < 10) { cout << 0 << i << '\n'; }
					else { cout << i << '\n'; }
					break;
				}
			}
		}

		T--;
		if (T < 1) { break; }
	}

	return 0;
}