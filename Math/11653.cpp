#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	int N; // �Է¹��� ��
	int m = 2; // ���

	cin >> N;

	while (N > 1) {
		if (N % m == 0) {
			cout << m << '\n';
			N = N / m;
		}
		else {
			m++;
		}
	}

	return 0;
}