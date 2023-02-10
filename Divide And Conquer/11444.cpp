#include <iostream>
#define MOD 1000000007
using namespace std;

typedef unsigned long long int number;

class Matrix2by2 {
public:
	int n = 2;
	number data[2][2] = { 0 };

	Matrix2by2() {
		this->set();
	}

	Matrix2by2(int a) {
		data[0][0] = a;
		data[0][1] = a;
		data[1][0] = a;
		data[1][1] = a;
	}

	void set() {
		data[0][0] = 1;
		data[0][1] = 1;
		data[1][0] = 1;
		data[1][1] = 0;
	}

	Matrix2by2 operator* (Matrix2by2 B) {
		Matrix2by2 tmp(0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					tmp.data[i][j] += (data[i][k] * B.data[k][j]) % MOD;
				}
				tmp.data[i][j] %= MOD;
			}
		}

		return tmp;
	}

	void show() {
		cout << data[0][0] << ' ' << data[0][1] << '\n';
		cout << data[1][0] << ' ' << data[1][1] << '\n';
	}
};

Matrix2by2 base;

Matrix2by2 fibo(number n) {
	Matrix2by2 tmp(0);

	if (n == 1) { return base; }
	if (n <= 0) { return tmp; }

	tmp = fibo(n / 2);

	if (n % 2 == 0) {
		return tmp * tmp;
	}
	else {
		return tmp * tmp * base;
	}
}

int main(int argc, char** argv) {
	number n;
	cin >> n;

	Matrix2by2 output = fibo(n);
	cout << output.data[0][1];

	return 0;
}