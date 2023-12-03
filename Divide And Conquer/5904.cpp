#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// 1,000,000,000개 까지면 대충 S(27)네

// M(k) = m o가 k+2개인 m o o 문자열
// 그러니까, S(k) = S(k-1) M(k) S(k-1)

// S(k-1)이랑 M(k)를 구해...? NO 메모리 초과

const int MAX = 30;
int cash[MAX] = { 0 };

// S(n)의 길이 구하는 함수
int get_lenght(int n) {

	if (n <= 0) {
		return 3;
	}

	int k_1 = cash[n - 1] == 0 ? get_lenght(n - 1) : cash[n - 1];
	int k3 = n + 3;

	cash[n] = k_1 + k3 + k_1;
	return cash[n];
}

int search(int k, int n) {
	cout << "k = " << k << ' ' << "n = " << n << '\n';

	if (k < 1) {
		return n;
	}
	
	cout << k - 1 << "번째의 길이 : " << cash[k - 1] << '\n';

	if (n <= cash[k - 1]) {
		return search(k - 1, n);
	}
	else if (cash[k - 1] < n && n <= (cash[k - 1] + k + 3)) {
		int idx = n - cash[k - 1];
		return idx;
	}
	else {
		return search(k - 1, n - cash[k - 1] - 3 - k);
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n;
	cash[0] = 3;
	k = log(n) + 8;
	
	// k번째 Moo 수열의 길이 L(k)는 L(k - 1) + (3 + k) + L(K - 1) 이니까 세 개를 구해서 어디에 속하는지 알아내기
	// 개수로 구하기
	get_lenght(k);

	int index = search(k, n);
	
	cout << "index " << index << '\n';

	if (index == 1) {
		cout << "m" << '\n';
	}
	else {
		cout << "o" << '\n';
	}

	return 0;
}