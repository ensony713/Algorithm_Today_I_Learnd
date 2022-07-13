#include <iostream>
using namespace std;

int main() {
	int count = 0, tmp;
	bool num[42] = { 0 };

	for (int i = 0; i < 10; i++) {
		cin >> tmp;
		if (!num[tmp % 42]) {
			count++;
			num[tmp % 42] = true;
		}
	}

	cout << count << '\n';
	return 0;
}