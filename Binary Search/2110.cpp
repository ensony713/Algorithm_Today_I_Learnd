#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long> house;

bool is_ok(int n, int c, long space) {

	int count = 1;
	long base = house[0];
	for (int i = 1; i < n; i++) {
		if (house[i] - base >= space) {
			count++;
			base = house[i];
		}
	}

	if (count >= c) {
		return true;
	}
	return false;
}

int binarySearch(int n, int c) {

	long start = 1, end = house[house.size() - 1] + 1, mid;

	while (start < end - 1) {

		mid = start + (end - start) / 2;

		if (is_ok(n, c, mid)) {
			start = mid;
		}
		else {
			end = mid;
		}
	}

	return start;
}

int main(int argc, char** argv) {
	int n, c;
	long input;

	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> input;
		house.push_back(input);
	}

	sort(house.begin(), house.end());

	cout << binarySearch(n, c);

	return 0;
}