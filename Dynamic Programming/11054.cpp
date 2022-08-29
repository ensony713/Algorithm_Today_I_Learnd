#include <iostream>
using namespace std;

int n;
int num[1000] = { 0 };
// index로 끝나는 증가하는 가장 긴 부분수열 (정)
int increase[1000] = { 0 };

// index로 끝나는 증가하는 가장 긴 부분수열 (역)
int decrease[1000] = { 0 };

int main(int argc, char** argv) {
	int max = 1, tmp;

	cin >> n;
	for (int i = 0; i < n; i++) {
		increase[i] = 1;
		decrease[i] = 1;
		cin >> num[i];
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < i; k++) {
			if (num[k] < num[i]) {
				increase[i] = increase[i] < increase[k] + 1 ?
					increase[k] + 1 : increase[i];
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int k = n - 1; k > i; k--) {
			if (num[i] > num[k]) {
				decrease[i] = decrease[i] < decrease[k] + 1 ?
					decrease[k] + 1 : decrease[i];
			}
		}

		tmp = decrease[i] + increase[i] - 1;
		max = max < tmp ? tmp : max;
	}

	for (int i = 0; i < n; i++) {
		cout << num[i] << " : " << increase[i] << " + " << decrease[i] << '\n';
	}

	cout << max;
	return 0;
}