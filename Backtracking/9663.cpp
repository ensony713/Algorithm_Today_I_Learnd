#include <iostream>
using namespace std;

int posit[20] = { 0 }; // ���� �����ִ� y ��ǥ / x ��ǥ = index
int result = 0, n;

bool is_passable(int x, int y) {

	for (int i = 0; i < x; i++) {

		if (y == posit[i]) { // ������
			return false;
		}

		if ((x + y) == (i + posit[i])) { // ������ �밢��
			return false;
		}

		if ((x - y) == (i - posit[i])) { // ������ �밢��
			return false;
		}
	}

	cout << "ok\n";
	return true;
}

void dfs(int deep) {
	if (deep == n) {
		result++;
		return;
	}

	// �� �ٿ� �ϳ����� ���� ������
	for (int i = 0; i < n; i++) {		

		if (is_passable(deep, i)) {
			posit[deep] = i;
			dfs(deep + 1);
		}
	}
}

int main(int argc, char* argv[]) {
	
	cin >> n;
	
	dfs(0);

	cout << result;
	return 0;
}