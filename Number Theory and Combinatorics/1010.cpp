#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	unsigned long long n, m, result = 1, t;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	for (int tc = 0; tc < t; tc++) {

		result = 1;
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			result *= (m - i);
			result /= (i + 1);
		}

		cout << result << '\n';
	}

	return 0;
}