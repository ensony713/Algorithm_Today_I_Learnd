#include <iostream>
using namespace std;

int main() {
	int x, n, end = 0, sep = 0, a, b;

	cin >> x;
	
	for (n = 1; end < x; n++) {
		end += n;
	}

	sep = x - (end - n);

	a = n + 1 - sep;
	b = n - a;

	if (n % 2 == 0) {
		cout << a << "/" << b;
	}
	else {
		cout << b << "/" << a;
	}

}