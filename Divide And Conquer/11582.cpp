#include <iostream>
using namespace std;

const int MAX = 1050000;

int arr[MAX] = { 0 };
int tmp[MAX] = { 0 };

void show(int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

void merge(int start, int mid, int end) {

	if (start >= end) {
		return;
	}

	int idx_i = start, idx_j = mid, idx = start;

	// 비교해서 작은거 먼저 집어넣기
	while (idx_i < mid && idx_j < end) {
		if (arr[idx_i] <= arr[idx_j]) {
			tmp[idx++] = arr[idx_i++];
		}
		else {
			tmp[idx++] = arr[idx_j++];
		}
	}

	// 남은 큰 수들 넣기
	for (int i = idx_i; i < mid; i++) {
		tmp[idx++] = arr[i];
	}
	for (int i = idx_j; i < end; i++) {
		tmp[idx++] = arr[i];
	}

	// 다시 쓰기
	for (int i = start; i < end; i++) {
		arr[i] = tmp[i];
	}
}

void divide(int start, int end, int n, int cnt) {

	if (start < end - 1) {

		int mid = (start + end) / 2;
		divide(start, mid, n, cnt * 2);
		divide(mid, end, n, cnt * 2);

		if (n <= cnt) {
			merge(start, mid, end);
		}
	}
}

int main(int argc, char** argv) {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> k;

	divide(0, n, k, 1);

	show(n);

	return 0;

	// 이거 그냥 병합정렬 아닌가 
	// 병합정렬에서 k개로 분할된 정렬 결과같은데
}