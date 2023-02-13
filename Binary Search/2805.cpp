#include <iostream>
#define MAX 100
using namespace std;

typedef unsigned long long int number;

bool is_ok(long* tree, number n, number m, long height) {
	
	number sum = 0;
	for (int i = 0; i < n; i++) {
		sum = tree[i] - height < 0 ? sum : sum + tree[i] - height;
	}

	if (sum >= m) { return true; }
	return false;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);

	number n, m;
	long tree[MAX] = { 0 };
	int s = 0, l = 0, h;
	number aver = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
		aver += tree[i];
		l = l < tree[i] ? tree[i] : l;
	}
	aver /= n;

	h = (aver - (m / n)) > 0 ? aver - (m / n) : 0;

	while (l - s > 1) {
		if (is_ok(tree, n, m, h)) {
			s = h;
		}
		else {
			l = h;
		}
		h = s + (l - s) / 2;
	}

	cout << s;
	return 0;
}