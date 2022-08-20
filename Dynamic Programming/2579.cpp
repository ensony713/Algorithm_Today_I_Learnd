#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	int n, one[305] = { 0 }, two[305] = { 0 }, step[305] = { 0 };

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> step[i];
	}

	one[0] = step[0];
	two[0] = step[0];
	one[1] = two[0] + step[1];
	two[1] = step[1];

	for (int i = 2; i < n; i++) {
		one[i] = two[i - 1] + step[i];
		two[i] = (one[i - 2] > two[i - 2] ? one[i - 2] : two[i - 2]) + step[i];
	}

	cout << (one[n - 1] > two[n - 1] ? one[n - 1] : two[n - 1]) << '\n';
	return 0;
}