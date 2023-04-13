#include <iostream>
#include <vector>
#include <cmath>
#define MAX 100
using namespace std;

void make_prime(vector<int>& prime, int n) {
	if (n < 2) { return ; }

	bool v[MAX] = { 0 };

	for (int i = 2; i <= n; i++) {
		if (!v[i]) {
			prime.push_back(i);

			for (int j = i * 2; j <= n; j += i) {
				v[j] = true;
			}
		}
	}
}

int counter(vector<int>& prime, int n) {

	int start = 0, end = 0, result = 0;
	int sum = prime[start];

	
	while (end < prime.size() - 1 && start < prime.size() - 1) {

		if (sum == n) { result++; }

		if (sum > n) {
			sum -= prime[start++];
		}
		else {
			sum += prime[++end];
		}
	}

	return result;
}

int main(int argc, char** argv) {

	vector<int> prime;
	int n;
	cin >> n;

	make_prime(prime, n);

	for (auto& p : prime) {
		cout << p << ' ';
	}
	cout << '\n';

	prime.push_back(0);
	cout << counter(prime, n);

	return 0;
}