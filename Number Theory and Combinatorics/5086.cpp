#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	int n, m;

	while (true) {
		cin >> n >> m;
		if (!n || !m) {
			return 0;
		}

		if (n % m == 0) {
			cout << "multiple\n";
		}
		else if (m % n == 0) {
			cout << "factor\n";
		}
		else {
			cout << "neither\n";
		}
	}

	return 0;
}