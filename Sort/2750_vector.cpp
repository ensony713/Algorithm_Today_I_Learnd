#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {

	int n, tmp;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for (auto a : v) {
		cout << a << '\n';
	}
}