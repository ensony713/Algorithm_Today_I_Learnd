#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
	int n, input, result = 0;
	vector<int> P;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		P.push_back(input);
	}

	sort(P.begin(), P.end());

	for (int i = 0; i < n; i++) {
		result += P[i] * (n - i);
	}

	cout << result;

	return 0;
}