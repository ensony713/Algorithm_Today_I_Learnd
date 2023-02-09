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

	Matrix operator+ (const Matrix& B) {
		Matrix tmp(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp.data[i][j] = data[i][j] + B.data[i][j];
			}
		}

		return tmp;
	}

	Matrix operator- (const Matrix& B) {
		Matrix tmp(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp.data[i][j] = data[i][j] - B.data[i][j];
			}
		}

		return tmp;
	}

	Matrix operator* (const Matrix& B) {
		Matrix tmp(this->n);
		int size = 1, s = n;

		if (n == 1 && B.n == 1) {
			tmp.data[0][0] = this->data[0][0] * B.data[0][0];

			return tmp;
		}

		while (s > size) { // 행렬을 네 개의 행렬로 분할하기 위해 2^n 꼴로 만듦
			size = size << 1;
		}

		s = size / 2;
		Matrix dA[5];
		Matrix dB[5];

		dA[1].set(s);	dA[2].set(s);	dA[3].set(s);	dA[4].set(s);
		dB[1].set(s);	dB[2].set(s);	dB[3].set(s);	dB[4].set(s);

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i < s && j < s) {
					dA[1].data[i % s][j % s] = this->data[i][j];
					dB[1].data[i % s][j % s] = B.data[i][j];
				}
				else if (i < s && j >= s) {
					dA[2].data[i % s][j % s] = this->data[i][j];
					dB[2].data[i % s][j % s] = B.data[i][j];
				}
				else if (i >= s && j < s) {
					dA[3].data[i % s][j % s] = this->data[i][j];
					dB[3].data[i % s][j % s] = B.data[i][j];
				}
				else {
					dA[4].data[i % s][j % s] = this->data[i][j];
					dB[4].data[i % s][j % s] = B.data[i][j];
				}
			}
		}

		Matrix M[8];
		for (int i = 1; i <= 7; i++) {
			M[i].set(s);
		}

		M[1] = (dA[1] + dA[4]) * (dB[1] + dB[4]);
		M[2] = (dA[3] + dA[4]) * dB[1];
		M[3] = dA[1] * (dB[2] - dB[4]);
		M[4] = dA[4] * (dB[3] - dB[1]);
		M[5] = (dA[1] + dA[2]) * dB[4];
		M[6] = (dA[3] - dA[1]) * (dB[1] + dB[2]);
		M[7] = (dA[2] - dA[4]) * (dB[3] + dB[4]);

		Matrix C[5];
		C[1].set(s);	C[2].set(s);	C[3].set(s);	C[4].set(s);
		C[1] = M[1] + M[4] - M[5] + M[7];
		C[2] = M[3] + M[5];
		C[3] = M[2] + M[4];
		C[4] = M[1] - M[2] + M[3] + M[6];

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i < s && j < s) {
					tmp.data[i][j] = C[1].data[i % s][j % s];
				}
				else if (i < s && j >= s) {
					tmp.data[i][j] = C[2].data[i % s][j % s];
				}
				else if (i >= s && j < s) {
					tmp.data[i][j] = C[3].data[i % s][j % s];
				}
				else {
					tmp.data[i][j] = C[4].data[i % s][j % s];
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
	if (B == 1) { return A; }

	Matrix tmp(A.row());
	tmp = square(A, B / 2);

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

	Matrix tmp = square(matrix, b);
	tmp.mod1000();
	tmp.show();

	return 0;
}