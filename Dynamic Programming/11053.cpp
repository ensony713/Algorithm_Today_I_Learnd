#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, max = 1;
	int num[1002] = { 0 }, lenght[1002] = { 0 };

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	lenght[0] = 1;

	for (int i = 1; i < n; i++) {

		lenght[i] = 1;

		for (int j = 0; j < i; j++) {
			if (num[i] > num[j]) {
				lenght[i] = lenght[i] > lenght[j] + 1 ? lenght[i] : lenght[j] + 1;
			}
		}

		max = max > lenght[i] ? max : lenght[i];
	}

	cout << max;
	return 0;
}