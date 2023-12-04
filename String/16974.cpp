#include <iostream>
#include <string>
using namespace std;

const int MAX = 500003;

// index 0���� ���� �ȵż� string���� �ȵǳ�..
// idx���� k���� ���ڿ� ������
void reverse(int idx, int k, int n, char str[]) {

	int half = idx + (k - 1) / 2;
	int term = k - 1;

	// Ȧ������ �߾� idx�� �ٲ� �ʿ䰡 �����ϱ� half ����
	if ((k % 2) == 1) {
		half--;
	}

	for (int i = idx; i <= half; i++) {
		//cout << i << " <-> " << i + term << '\n';

		char tmp = str[i];
		str[i] = str[i + term];
		str[i + term] = tmp;
		term -= 2;
	}
}

// s���� e���� ���
void show(int s, int e, char str[]) {

	for (int i = s; i <= e; i++) {
		cout << str[i];
	}
	cout << '\n';
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	char str[MAX] = { 0 };

	cin >> n >> k;
	
	// ���ڿ� �Է�
	for (int i = 1; i <= n; i++) {
		cin >> str[i];
	}

	// n == k�� �׳� ����� ���
	if (n == k) {
		reverse(1, k, n, str);
		show(1, n, str);
		return 0;
	}

	// k���� ������
	for (int i = k; i <= n; i++) {
		cout << str[i];
	}

	// �տ��� (k - 1)����, n�� k�� Ȧ¦���� ��ġ = ������ / ����ġ = ����
	// �翬�� ������ �����Ⱑ Ȧ���� �Ͼ�� �ٸ��� ¦���� �Ͼ�ϱ�
	if ((n % 2) == (k % 2)) {
		reverse(1, k - 1, n, str);
	}
	show(1, k - 1, str);

	return 0;
}