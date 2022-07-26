#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	int N; // 입력받은 수
	int m = 2; // 약수

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