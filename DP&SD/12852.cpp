#include <iostream>
#define MAX 1000002
using namespace std;

int n;
int memo[MAX] = { 0 };

int dp(int x) {

	if (x <= 1) { return 0; }

	if (memo[x] != 0) { return memo[x]; }

	int tmp;
	memo[x] = MAX;

	if (x % 3 == 0) {
		tmp = dp(x / 3) + 1;
		memo[x] = tmp;
	}

	if (x % 2 == 0) {
		tmp = dp(x / 2) + 1;
		
		if (memo[x] > tmp) {
			memo[x] = tmp;
		}
	}

	tmp = dp(x - 1) + 1;
	if (memo[x] > tmp) {
		memo[x] = tmp;
	}

	return memo[x];
}

int main(int argc, char** argv) {
	
	cin >> n;
	
	int num = n;

	cout << dp(n) << '\n';

	while (num > 1) {
		cout << num << ' ';

		if (num % 3 == 0 && memo[num / 3] + 1 == memo[num]) {
			num = num / 3;
			continue;
		}

		if (num % 2 == 0 && memo[num / 2] + 1 == memo[num]) {
			num = num / 2;
			continue;
		}

		if (memo[num - 1] + 1 == memo[num]) {
			num = num - 1;
			
		}
	}
	cout << 1 << '\n';

	return 0;
}