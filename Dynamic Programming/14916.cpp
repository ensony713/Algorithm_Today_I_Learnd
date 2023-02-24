#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;

int cache[MAX] = { 0 };

int dp(int n) {
	if (n <= 1 || n == 3) {
		return -1;
	}

	if (cache[n] != 0) {
		return cache[n];
	}

	int five = dp(n - 5) + 1, two = dp(n - 2) + 1;
	
	if (two != 0 && five != 0) {
		cache[n] = min(two, five);
	}
	else if (two != 0) {
		cache[n] = two;
	}
	else if (five != 0) {
		cache[n] = five;
	}

	return cache[n];
}

int main(int argc, char** argv) {

	int n;

	cin >> n;

	cache[2] = 1;
	cache[5] = 1;

	cout << dp(n) << '\n';
	return 0;
}