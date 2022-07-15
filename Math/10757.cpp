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

	// �ڸ� ���߱�
	while (a.length() != b.length()) {
		if (a.length() < b.length()) {
			a = "0" + a;
		}
		else {
			b = "0" + b;
		}
	}

	// ���� ���� �ڸ��� index
	size = a.length() - 1;

	// ����
	for (int i = 0; i < size; i++) {
		num[i] += a[size - i] - 48 + b[size - i] - 48;

		if (num[i] > 9) {
			num[i] = num[i] % 10;
			num[i + 1]++;
		}
	}

	// ���� ū �ڸ����� �ø��� �ʰ� �״�� ����
	num[size] += a[0] + b[0] - 96;

	// �� �ڸ��� ���� 0 �ڸ������� ����
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