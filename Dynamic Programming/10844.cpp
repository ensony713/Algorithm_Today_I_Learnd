#include <iostream>
#define MAX 1000000000
using namespace std;

typedef unsigned long long number;

number num[101][10] = { 0 };
number result = 0;

int main(int argc, char** argv) {
	int n;
	cin >> n;

	for (int i = 1; i < 10; i++) {
		num[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				num[i][j] = num[i - 1][1];
			}
			else if (j == 9) {
				num[i][j] = num[i - 1][8];
			}
			else {
				num[i][j] = (num[i - 1][j - 1] + num[i - 1][j + 1]) % MAX;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		result = (result + num[n][i]) % MAX;
	}

	cout << result;
	return 0;
}