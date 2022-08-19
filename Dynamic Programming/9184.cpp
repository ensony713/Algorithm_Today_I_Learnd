#include <iostream>
using namespace std;

int arr[21][21][21] = { 0 };

int w(int a, int b, int c) {
	int tmp;

	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}

	if (a > 20 || b > 20 || c > 20) {
		a = 20;
		b = 20;
		c = 20;
	}

	if (arr[a][b][c] != 0) {
		return arr[a][b][c];
	}

	if (a < b && b < c) {
		tmp = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	} else {
		tmp = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}

	arr[a][b][c] = tmp;
	return tmp;
}

int main(int argc, char* agrv[]) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int a, b, c;

	while (true) {
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1) {
			return 0;
		}

		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}
}