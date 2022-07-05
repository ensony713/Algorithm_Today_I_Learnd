#include <iostream>
using namespace std;

long n, c = 0, result;

bool is666(long num) {
	long i = 100000000, t, count = 0;

	while (true) {
		if (i == 0) {
			return false;
		}

		t = (num / i) % 10;

		if (t == 6) { ++count; }
		else { count = 0; }
		
		if (count == 3) {
			return true;
		}

		i = i / 10;
	}
}

int main() {
	cin >> n;
	
	for (long i = 666; c < n; i++) {
		if (is666(i)) {
			c++;
			result = i;
		}
	}
	cout << result;

	return 0;
}