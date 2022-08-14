#include <iostream>
using namespace std;

int posit[20] = { 0 }; // 퀸이 놓여있는 y 좌표 / x 좌표 = index
int result = 0, n;

bool is_passable(int x, int y) {

	for (int i = 0; i < x; i++) {

		if (y == posit[i]) { // 세로줄
			return false;
		}

		if ((x + y) == (i + posit[i])) { // 역방향 대각선
			return false;
		}

		if ((x - y) == (i - posit[i])) { // 정방향 대각선
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

	// 한 줄에 하나씩만 선택 가능함
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