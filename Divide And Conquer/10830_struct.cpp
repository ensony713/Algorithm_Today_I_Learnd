#include <iostream>
#define MAX 6
using namespace std;

typedef unsigned long long int number;

struct Matrix {
	number data[MAX][MAX] = { 0 };
	int n;
};

void mod1000(Matrix& m, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m.data[i][j] %= 1000;
		}
	}
};

Matrix mul(Matrix* a, Matrix* b) {
	Matrix tmp;
	tmp.n = a->n;

	for (int i = 0; i < a->n; i++) {
		for (int j = 0; j < a->n; j++) {
			tmp.data[i][j] = 0;
			for (int k = 0; k < a->n; k++) {
				tmp.data[i][j] += a->data[i][k] * b->data[k][j];
			}
		}
	}

	return tmp;
}

Matrix square(Matrix A, number B) {
	if (B == 1) {
		return A;
	}

	Matrix tmp = square(A, B / 2);
	mod1000(tmp, tmp.n);
	Matrix result = mul(&tmp, &tmp);
	mod1000(result, result.n);

	if (B % 2 == 0) {
		return result;
	}
	return mul(&A, &result);
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	number b;
	Matrix matrix;
	cin >> matrix.n >> b;
	
	for (int i = 0; i < matrix.n; i++) {
		for (int j = 0; j < matrix.n; j++) {
			cin >> matrix.data[i][j];
		}
	}

	Matrix tmp = square(matrix, b);
	mod1000(tmp, tmp.n);

	for (int i = 0; i < tmp.n; i++) {
		for (int j = 0; j < tmp.n; j++) {
			cout << tmp.data[i][j];

			if (j != tmp.n - 1) { cout << ' '; }
		}
		cout << '\n';
	}

	return 0;
}