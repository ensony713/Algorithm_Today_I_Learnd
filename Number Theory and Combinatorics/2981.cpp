#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int main(int argc, char* []) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> num, diff, result;
	bool pass;
	int n, input, mini, tmp;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> input;
		num.push_back(input);
	}

	sort(num.begin(), num.end());

	for (int i = 0; i < num.size() - 1; i++) {
		tmp = num[i + 1] - num[i];
		diff.push_back(tmp);
	}

	mini = diff[0];
	for (int d : diff) {
		mini = gcd(d, mini);
	}

	for (int i = 2; i <= sqrt(mini); i++) {
		if (mini % i == 0) {
			cout << i << ' ';

			if (mini / i != i) {
				result.push_back(mini / i);
			}
		}
	}

	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << ' ';
	}

	cout << mini << '\n';

	return 0;
}