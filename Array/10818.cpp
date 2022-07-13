#include <iostream>
using namespace std;

int main() {
	int N, maxi = -2000000, mini = 2000000, tmp;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		maxi = tmp > maxi ? tmp : maxi;
		mini = tmp < mini ? tmp : mini;
	}

	cout << mini << " " << maxi << "\n";

	return 0;
}