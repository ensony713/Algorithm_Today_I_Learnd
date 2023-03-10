#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;

typedef unsigned long long number;

int segt[MAX] = { 0 }; // 최솟값의 index를 가진 segment tree
number input[MAX] = { 0 };

int init(int start, int end, int idx) {

	if (start == end) { return segt[idx] = start; }

	int mid = start + (end - start) / 2;
	int left = init(start, mid, idx * 2);
	int right = init(mid + 1, end, idx * 2 + 1);

	if (input[left] < input[right]) {
		segt[idx] = left;
	}
	else {
		segt[idx] = right;
	}

	return segt[idx];
}

// left, right = 찾으려는 구간의 시작과 끝
// start, end = 현재 확인하고 있는 구간의 시작과 끝
// base = 지금 확인하고 있는 노드
// 반환 = 구간의 최솟값 index
int search(int left, int right, int start, int end, int base) {

	if (left > end || right < start) {
		return -1;
	}

	if (left <= start && end <= right) {
		return segt[base];
	}

	int l = search(left, right, start, (start + end) / 2, base * 2);
	int r = search(left, right, (start + end) / 2 + 1, end, base * 2 + 1);

	if (l == -1) { return r; }
	if (r == -1) { return l; }

	if (input[l] < input[r]) { return l; }
	return r;
}

number bigger(int start, int end, int n) {

	int base = search(start, end, 0, n - 1, 1);
	// start부터 end까지 input 중에서 가장 작은 곳의 index

	number area = (number)(end - start + 1) * input[base];
	// input[base]를 포함하는 가장 큰 직사각형의 넓이

	number tmp;

	if (start <= base - 1) { // base의 왼쪽
		tmp = bigger(start, base - 1, n);
		area = area > tmp ? area : tmp;
	}

	if (end >= base + 1) { // base의 오른쪽
		tmp = bigger(base + 1, end, n);
		area = area > tmp ? area : tmp;
	}

	return area;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;

	while (1) {
		cin >> n;

		if (n == 0) {
			break;
		}

		for (int i = 0; i < n; i++) {
			cin >> input[i];
		}
		init(0, n - 1, 1);

		cout << bigger(0, n - 1, n) << '\n';
	}

	// 구간의 최솟값을 저장하는 세그먼트 트리
	return 0;
}