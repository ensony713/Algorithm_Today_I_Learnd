#include <iostream>
#include <string>
using namespace std;

int main() {
	short* num = new short[10001]{ 0 };
	int size = 0;
	char tmp;
	string a, b;
	bool zero, check = true;

	cin >> a >> b;

	// 자리 맞추기
	while (a.length() != b.length()) {
		if (a.length() < b.length()) {
			a = "0" + a;
		}
		else {
			b = "0" + b;
		}
	}

	// 가장 작은 자릿수 index
	size = a.length() - 1;

	// 덧셈
	for (int i = 0; i < size; i++) {
		num[i] += a[size - i] - 48 + b[size - i] - 48;

		if (num[i] > 9) {
			num[i] = num[i] % 10;
			num[i + 1]++;
		}
	}

	// 가장 큰 자릿수는 올리지 않고 그대로 저장
	num[size] += a[0] + b[0] - 96;

	// 앞 자리에 오는 0 자르기위한 변수
	zero = num[size] != 0;
	for (int i = size; i >= 0; i--) {
		if (zero) {
			cout << num[i];
			check = false;
		}
		zero = !zero && num[i - 1] == 0 ? false : true;
	}

	if (check) cout << 0;

	return 0;
}