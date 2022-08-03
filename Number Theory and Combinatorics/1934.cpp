#include <iostream>
using namespace std;

int gcd(int n, int m) {
	if (n % m == 0) { return m; }
	else { return gcd(m, n % m); }
}

int lcm(int n, int m) {
	return n * m / gcd(n, m);
}

int main(int argc, char* argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, t;
	cin >> t;

	for (int tc = 0; tc < t; tc++) {
		cin >> n >> m;
		cout << lcm(n, m) << '\n';
	}

	return 0;
}