#include <iostream>
using namespace std;

int main() {
	int N, tmp = 0, mini = 10000, counter = 0, rest;

	cin >> N;
	tmp = N / 5;

	while (tmp >= 0) {
		counter = tmp;

		rest = N - (tmp * 5);
		
		if (rest % 3 == 0) {
			counter += rest / 3;
			mini = mini > counter ? counter : mini;
		}

		tmp--;
	}

	mini = mini == 10000 ? -1 : mini;
	cout << mini;

	return 0;
}