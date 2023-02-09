#include <iostream>
#define MAX 6
using namespace std;

typedef unsigned long long int number;

class Matrix {
private:
	int n = 0;

public:
	Matrix() {}
	Matrix(int a) {
		n = a;
	}

	number data[MAX][MAX] = { 0 };

	void set(int n) { this->n = n; }
	int row() { return n; }

	void mod1000() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				data[i][j] %= 1000;
			}
		}
	};

	Matrix mul(Matrix a) {
		Matrix tmp(n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp.data[i][j] = 0;
				for (int k = 0; k < n; k++) {
					tmp.data[i][j] += data[i][k] * a.data[k][j];
				}
			}
		}

		return tmp;
	}

	Matrix operator* (const Matrix& A) {
		Matrix tmp(n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp.data[i][j] = 0;
				for (int k = 0; k < n; k++) {
					tmp.data[i][j] += data[i][k] * A.data[k][j];
				}
			}
		}

		return tmp;
	}

	void show() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << data[i][j] << ' ';
			}
			cout << '\n';
		}
	}
};

Matrix square(Matrix A, number B) {
	if (B == 1) {
		return A;
	}

	Matrix tmp(A.row());
	tmp = square(A, B / 2);
	tmp.mod1000();

	Matrix result(A.row());
	result = tmp.mul(tmp);
	result.mod1000();

	if (B % 2 == 0) {
		return result;
	}
	return result.mul(A);
}

Matrix square2(Matrix A, number B) {
	if (B == 1) { return A; }

	Matrix tmp(A.row());
	tmp = square2(A, B / 2);

	Matrix result(A.row());
	result = tmp * tmp;
	result.mod1000();

	if (B % 2 == 0) {
		return result;
	}
	return result * A;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	number b;
	int n;
	Matrix matrix;
	cin >> n >> b;
	matrix.set(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix.data[i][j];
		}
	}

	Matrix tmp = square2(matrix, b);
	tmp.mod1000();
	tmp.show();

	return 0;
}