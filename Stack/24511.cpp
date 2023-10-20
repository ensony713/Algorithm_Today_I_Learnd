#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

// stack => ������ ���� �ǹ� �����ϱ� ��ŵ
// queue => �̰� push pop �ʿ�

const int MAX = 100004;
int a[MAX]; // i�� �ڷᱸ���� ť���� ��������

int result[MAX];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m; // ������ ���� ����
	int n; // �ڷᱸ�� ����
	int next; // ������ ���� ����
	cin >> n;

	deque<int> b; // i�� �ڷᱸ���� ����ִ� ����

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