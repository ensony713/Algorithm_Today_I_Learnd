#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int main(int argc, char* argv) {
	int n, g;
	int first, input;

	cin >> n;
	cin >> first;

	for (int i = 1; i < n; i++) {
		cin >> input;
		g = gcd(first, input);
		cout << first / g << "/" << input / g << '\n';
	}

	return 0;
}