#include <iostream>
using namespace std;

bool prime_number(int n) {
	if (n == 1) return false;

	for (int i = 2; i < n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N; // M부터 N사이의 소수 찾기
	bool *arr = new bool[1000001] { 0 }; // 소수인지 아닌지 판별하기 위한 배열
	// 소수이면 false, 소수가 아니면 true
	int pn[1000] = { 0 }, index = 0; // 소수 배열

	cin >> M >> N;
	
	arr[1] = true;

	// 2 ~ 997 사이의 소수 배열 생성
	for (int i = 2; i < 1000; i++) { 
		if (prime_number(i)) pn[index++] = i;
	}

	// 소수의 배수들을 제외
	for (int i = 0; i < index; i++) {
		for (int j = 2; j * pn[i] <= N; j++) {
			arr[j * pn[i]] = true;
		}
	}

	for (int i = M; i <= N; i++) {
		if (!arr[i]) cout << i << '\n';
	}
	
	delete[] arr;
	return 0;
}