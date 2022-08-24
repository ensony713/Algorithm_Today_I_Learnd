#include <iostream>
using namespace std;

int num[10003] = { 0 }, jump[10003] = { 0 }, sq[10003] = { 0 };

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, max;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}

	jump[1] = num[1];
	sq[1] = num[1];
	max = num[1];

	for (int i = 2; i <= n; i++) {
		jump[i] = num[i];
		for (int j = 0; j < i - 1; j++) {
			jump[i] = jump[i] > jump[j] + num[i] ? jump[i] : jump[j] + num[i];
			jump[i] = jump[i] > sq[j] + num[i] ? jump[i] : sq[j] + num[i];
		}
		sq[i] = jump[i - 1] + num[i];

		max = max < jump[i] ? jump[i] : max;
		max = max < sq[i] ? sq[i] : max;
	}

	cout << max;
	return 0;
}