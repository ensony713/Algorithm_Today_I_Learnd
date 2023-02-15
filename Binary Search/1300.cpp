#include <iostream>
using namespace std;

typedef unsigned long long number;

number numberth(int n, number k) { 
	// 배열 B에서, k이하의 수는 몇 개인지 구하는 함수
	number result = 0;
	for (int i = 1; i <= n; i++) {
		result += (k / i < n ? k / i : n);
	}

	cout << k << "이하의 수 " << result << "개\n";
	
	return result;
}

number binarySearch(int n, number k) {

	number small = 1, large = k, mid = 1;
	number num;

	while (small <= large) {

		mid = (large + small) / 2;
		num = numberth(n, mid);

		if (num < k) {
			small = mid + 1;
		}
		else {
			large = mid - 1;
		}
	}

	return small;
}

int main(int argc, char** argv) {

	int n;
	number k;

	cin >> n >> k;

	cout << binarySearch(n, k);
	
	return 0;
}