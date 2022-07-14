#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
	int N, tmp = 0;
	vector <int> list, sorted;
	map <int, int> result;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		list.push_back(tmp);
		sorted.push_back(tmp);
	}

	sort(sorted.begin(), sorted.end());

	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

	for (int i = 0; i < sorted.size(); i++) {
		result.insert(make_pair(sorted[i], i));
	}

	for (int i = 0; i < list.size(); i++) {
		cout << result[list[i]] << " ";
	}

	return 0;
}