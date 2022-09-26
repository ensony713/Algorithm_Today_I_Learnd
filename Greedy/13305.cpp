#include <iostream>
#define MAX 100
using namespace std;

typedef unsigned long long number;

int main(int argc, char** argv) {
	int n, cost[MAX] = { 0 }, km[MAX] = { 0 }, oil;
	number sum = 0, lenght = 0;

	cin >> n;
	for (int i = 0; i < n - 1; i++) { cin >> km[i]; }
	for (int i = 0; i < n; i++) { cin >> cost[i]; }

	oil = cost[0];
	for (int i = 0; i < n-1; i++) {
		if (oil > cost[i]) { oil = cost[i]; }
		sum += oil * (number)km[i];
	}

	cout << sum;
	return 0;
}