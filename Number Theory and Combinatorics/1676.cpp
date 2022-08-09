#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	int n, two = 0, five = 0;

	cin >> n;

	for (int i = 2; i <= n; i++) {
		
		for (int j = i; j % 2 == 0; j /= 2) {
			two++;
		}

		for (int j = i; j % 5 == 0; j /= 5) {
			five++;
		}
	}

	cout << (two < five ? two : five) << '\n';

	return 0;
}