#include <iostream>
#define MAX 1000
using namespace std;

int cache[MAX] = { 0 };

int dp(int n) {
	if (n < 0) {
		return -1;
	}

	if (cache[n] != 0) {
		return cache[n];
	}

	int one = dp(n - 1) + 1, three = dp(n - 3) + 1;

	if (three < 0) { cache[n] = one; }
	else { cache[n] = one < three ? one : three; }

	return cache[n];
}

int main(int argc, char** argv) {
	int n;
	cin >> n;

	cache[0] = 1;
	cache[1] = 1;

	if (dp(n) % 2 == 0) {
		cout << "SK\n";
	}
	else {
		cout << "CY\n";
	}
}