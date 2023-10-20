#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

// stack => 넣으나 마나 의미 없으니까 스킵
// queue => 이건 push pop 필요

const int MAX = 100004;
int a[MAX]; // i번 자료구조가 큐인지 스택인지

int result[MAX];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m; // 삽입할 수열 길이
	int n; // 자료구조 개수
	int next; // 다음에 넣을 원소
	cin >> n;

	deque<int> b; // i번 자료구조에 들어있는 원소

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (a[i] == 0) {
			b.push_back(input);
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> next;
		b.push_front(next);

		result[i] = b.back();
		b.pop_back();
	}
	
	for (int i = 0; i < m; i++) {
		cout << result[i] << " ";
	}
	cout << '\n';

	return 0;
}