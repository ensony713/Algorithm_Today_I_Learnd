#include <iostream>
using namespace std;

int lenght[1003][1003] = { 0 };

int main(int argc, char** argv) {
	string a, b;
	int max = 0;

	cin >> a >> b;

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {

			if (a[i - 1] == b[j - 1]) {
				lenght[i][j] = lenght[i - 1][j - 1] + 1;
			}
			else {
				lenght[i][j] = lenght[i - 1][j] > lenght[i][j - 1] ?
					lenght[i - 1][j] : lenght[i][j - 1];
			}

			max = max > lenght[i][j] ? max : lenght[i][j];
		}
	}
	cout << max;

	return 0;
}