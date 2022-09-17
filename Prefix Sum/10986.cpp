#include <iostream>
#define MAX 1003
using namespace std;

typedef long long number;

int n, m;
number input, result = 0;
number A[MAX] = { 0 }, cnt[1010] = { 0 };

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	cin >> A[0];
	A[0] = A[0] % (number)m;
	cnt[A[0]]++;

	for (int i = 1; i < n; i++) {
		cin >> input;
		A[i] = (A[i - 1] + input) % (number) m;
		cnt[A[i]]++;
	}

	result += cnt[0];
	for (int i = 0; i < m; i++) {
		result += (cnt[i] * (cnt[i] - 1)) / 2;
	}

	cout << result;
	return 0;
}