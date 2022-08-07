#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	int n, k;
	long long dp[1005] = { 0 };

	cin >> n >> k;

	dp[0] = 1;

	for (int i = 0; i <= n; i++) {
		for (int j = i; j >= 0; j--) {
			if (j != 0) {
				dp[j] = (dp[j - 1] + dp[j]) % 10007;
			}
			if (i == n && j == k) {
				cout << dp[j] << "\n";
				return 0;
			}
		}
	}

	return 0;
}

/* ��ⷯ ������ ���, �������� �й� ��Ģ�� �������� �����Ƿ� �Ʒ��� Ǯ�̴� Ʋ����
* (a / b) % c  !=  (a % c) / (b % c)
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	long n, k;
	long result = 1;

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		result = (result * (n - i)) % 10007;
	}

	for (int i = 2; i <= k; i++) {
		result = (result / i) % 10007;
	}

	cout << result;

	return 0;
}
*/