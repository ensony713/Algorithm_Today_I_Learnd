#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void get_input(vector<int>& l, int n) {

	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		l.push_back(input);
	}
}

int counter(vector<int>& list, int m) {

	int start = 0, end = list.size() - 1 , result = 0;

	while (start < end) {
		
		if (list[start] + list[end] == m) { result++; }
		
		if (list[start] + list[end] >= m) {
			end--;
		}
		else {
			start++;
		}
	}

	return result;
}

int main(int argc, char** argv) {
	int n; // 재료 개수
	int m; // 갑옷을 만들기 위한 최소값
	vector<int> list;
	cin >> n >> m;

	get_input(list, n);

	sort(list.begin(), list.end());

	cout << counter(list, m);

	return 0;
}