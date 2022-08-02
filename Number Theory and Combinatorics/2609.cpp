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
	int n, m;
	cin >> n >> m;

	cout << gcd(n, m) << '\n';
	cout << lcm(n, m) << '\n';
	return 0;
}