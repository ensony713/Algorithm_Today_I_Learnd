#include <iostream>
#define MAX 10
using namespace std;

class Matrix {
private:
	int n = 0, m = 0; //n행 m열

public:
	int data[MAX][MAX] = { 0 };

	Matrix() {}

	Matrix(int a, int b) {
		n = a;
		m = b;
	}

	void set(int a, int b) {
		n = a;
		m = b;
	}

	void set_sq(int a) {
		n = a;
		m = a;
	}

	void reset() { // 백준에선 오류나네;
		memset(data, 0, sizeof(data));
	}

	int row() { return n; }
	int col() { return m; }

	Matrix operator+ (const Matrix& B) {
		Matrix tmp(n, m);
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp.data[i][j] = this->data[i][j] + B.data[i][j];
			}
		}
		return tmp;
	}

	Matrix operator- (const Matrix& B) {
		Matrix tmp(n, m);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp.data[i][j] = this->data[i][j] - B.data[i][j];
			}
		}
		return tmp;
	}

	Matrix operator* (const Matrix& B) {

		Matrix tmp(this->n, B.m);
		int size = 1, s;

		if (n == 1 && m == 1 && B.n == 1 && B.m == 1) {
			tmp.data[0][0] = this->data[0][0] * B.data[0][0];

			return tmp;
		}

		if (n > m) { s = n; }
		else { s = m; }

		while (s > size) { // 행렬을 네 개의 행렬로 분할하기 위해 2^n 꼴로 만듦
			size = size << 1;
		}
		
		s = size / 2;
		Matrix dA[5];
		Matrix dB[5];
		
		dA[1].set_sq(s);	dA[2].set_sq(s);	dA[3].set_sq(s);	dA[4].set_sq(s);
		dB[1].set_sq(s);	dB[2].set_sq(s);	dB[3].set_sq(s);	dB[4].set_sq(s);

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
			M[i].set_sq(s);
		}

		M[1] = (dA[1] + dA[4]) * (dB[1] + dB[4]);
		M[2] = (dA[3] + dA[4]) * dB[1];
		M[3] = dA[1] * (dB[2] - dB[4]);
		M[4] = dA[4] * (dB[3] - dB[1]);
		M[5] = (dA[1] + dA[2]) * dB[4];
		M[6] = (dA[3] - dA[1]) * (dB[1] + dB[2]);
		M[7] = (dA[2] - dA[4]) * (dB[3] + dB[4]);

		Matrix C[5];
		C[1].set_sq(s);	C[2].set_sq(s);	C[3].set_sq(s);	C[4].set_sq(s);
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

	void showAll() {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cout << data[i][j];

				if (j != MAX - 1) { cout << ' '; }
			}
			cout << '\n';
		}
		cout << '\n';
	}

	void show() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << data[i][j];

				if (j != m - 1) { cout << ' '; }
			}
			cout << '\n';
		}
		cout << '\n';
	}
};

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	Matrix A, B;

	cin >> n >> m;
	A.set(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A.data[i][j];
		}
	}

	cin >> m >> k;
	B.set(m, k);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> B.data[i][j];
		}
	}

	(A * B).show();

	return 0;
}