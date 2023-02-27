#include <iostream>
#define MAX 100
using namespace std;

int num[MAX] = { 0 };
int decr[MAX] = { 0 }, incr[MAX] = { 0 };

int main(int argc, char** argv) {
	int n, max = 0;
	cin >> n;

	decr[0] = 1;
	incr[0] = 1;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
		if (i != 0) {
			decr[i] = num[i - 1] >= num[i] ? decr[i - 1] + 1 : 1;
			incr[i] = num[i - 1] <= num[i] ? incr[i - 1] + 1 : 1;
		}

		max = max < decr[i] ? decr[i] : max;
		max = max < incr[i] ? incr[i] : max;
	}

	cout << max;

	return 0;
}