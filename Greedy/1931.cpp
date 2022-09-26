#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sorted(pair<int, int> & a, pair<int, int> & b) {
	if (a.second < b.second) { return true; }
	if (a.second == b.second && a.first < b.first) { return true; }
	else { return false; }
}

int main(int argc, char** argv) {
	vector<pair<int, int>> time;
	int n, start, end, last = 0, result = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		time.push_back(make_pair(start, end));
	}

	sort(time.begin(), time.end(), sorted);
	
	for (auto a : time) {
		if (last <= a.first) {
			result++;
			last = a.second;
		}
	}

	cout << result;

	return 0;
}