#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int cache[MAX] = { 0 };

int dp(int n) {
	if (n < 0) {
		return MAX;
	}

	if (cache[n] != 0) {
		return cache[n];
	}

	cache[n] = min(dp(n - 1) + 1, dp(n - 3) + 1);

	return cache[n];
}

int main(int argc, char** argv) {

	int n, count;
	cin >> n;

	cache[1] = 1;
	cache[3] = 1;

	count = dp(n);
	if (count % 2 == 0) {
		cout << "CY\n";
	}
	else {
		cout << "SK\n";
	}

	return 0;
}