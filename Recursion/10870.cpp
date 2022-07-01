#include <iostream>
using namespace std;

int fivo(int n) {
	if (n < 1) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}

	return fivo(n - 1) + fivo(n - 2);
}

int main() {
	int N;

	cin >> N;
	cout << fivo(N);

	return 0;
}