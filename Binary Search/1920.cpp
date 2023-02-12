#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long> A;

bool half(int start, int end, long num) {

	cout << "half(" << start << ", " << end << ")\n";

	if (start == end) {
		return num == A[start];
	}

	int i = (end - start) / 2;

	if (A[start + i] < num) {
		return half(start + i + 1, end, num);
	}
	else if (A[start + i] > num) {
		return half(start, start + i, num);
	}
	else {
		return true;
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	long input;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		A.push_back(input);
	}

	sort(A.begin(), A.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> input;
		if (half(0, A.size() - 1, input)) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
}