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

	// ���ؼ� ������ ���� ����ֱ�
	while (idx_i < mid && idx_j < end) {
		if (arr[idx_i] <= arr[idx_j]) {
			tmp[idx++] = arr[idx_i++];
		}
		else {
			tmp[idx++] = arr[idx_j++];
		}
	}

	// ���� ū ���� �ֱ�
	for (int i = idx_i; i < mid; i++) {
		tmp[idx++] = arr[i];
	}
	for (int i = idx_j; i < end; i++) {
		tmp[idx++] = arr[i];
	}

	// �ٽ� ����
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

	// �̰� �׳� �������� �ƴѰ� 
	// �������Ŀ��� k���� ���ҵ� ���� ���������
}