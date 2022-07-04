#include <iostream>
#include <string>
using namespace std;

int main() {
	string n, index;
	int i, N, sum = 0;

	cin >> n;
	N = stoi(n);

	for (i = 1; i < N; i++) {
		index = to_string(i);
		sum = 0;
		
		for (char c : index) {
			sum = sum + c - 48;
		}
		sum += i;

		if (sum == N) {
			cout << i;
			break;
		}
	}

	if (i == N) { cout << 0; }
	return 0;
}