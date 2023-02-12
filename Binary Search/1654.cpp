#include <iostream>
#define MAX 100
using namespace std;

typedef unsigned long long int number;

long lan[MAX] = { 0 };

bool is_ok(int n, int k, long lenght) { // lenght 길이의 lan선을 만들 수 있는지
	int count = 0;

	for (int i = 0; i < k; i++) {
		count += lan[i] / lenght;
		if (count >= n) { return true; }
	}
	return false;
}

long cutLine(int n, int k, long lenght) {
	long small = 1, large = lenght, result = 1;
	
	if (is_ok(n, k, lenght)) { return lenght; }

	while (small + 1 < large) {

		result = small + (large - small) / 2;
		if (is_ok(n, k, result)) {
			small = result;
		}
		else {
			large = result;
		}
	}

	return small;
}

int main(int argc, char** argv) {
	int n, k;
	number sum = 0;
	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		cin >> lan[i];
		sum += lan[i];
	}
	
	cout << cutLine(n, k, sum / n);
	return 0;
}