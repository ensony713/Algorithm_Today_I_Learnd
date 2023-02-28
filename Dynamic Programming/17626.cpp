#include <iostream>
#include <cmath>
#define MAX 50005
using namespace std;

int cache[MAX] = { 0 };

int dp(int num) {
	if (num <= 0) { return 0; }

	if (cache[num] != 0) {
		return cache[num];
	}

	int tmp = 0, mini = num;
	for (int i = 1; i <= sqrt(num); i++) {
		tmp = dp(num - (i * i)) + 1;
		mini = tmp < mini ? tmp : mini;
	}

	cache[num] = mini;
	return cache[num];
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	cache[1] = 1;

	cout << dp(n);

	return 0;
}