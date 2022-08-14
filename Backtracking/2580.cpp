#include <iostream>
#include <vector>
using namespace std;

struct point {
	int x, y;
};

int board[9][9] = { 0 };
int blank_size = 0;
point blanks[81];

vector<int> passable_num(int x, int y) {

	vector<int> num;
	bool passable[10] = { 0 };

	for (int i = 0; i < 9; i++) {
		passable[board[x][i]] = true;
		passable[board[i][y]] = true;
	}

	int startX = x / 3;
	int startY = y / 3;
	for (int i = startX * 3; i < startX * 3 + 3; i++) {
		for (int j = startY * 3; j < startY * 3 + 3; j++) {
			passable[board[i][j]] = true;
		}
	}

	for (int i = 1; i < 10; i++) {
		if (!passable[i]) {
			num.push_back(i);
		}
	}

	return num;
}

void dfs(int deep) {

	if (deep >= blank_size) {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << " ";
			}
			cout << '\n';
		}
		exit(0);
	}

	int x = blanks[deep].x, y = blanks[deep].y;
	vector<int> num = passable_num(x, y);

	for (int n : num) {
		board[x][y] = n;
		dfs(deep + 1);
		board[x][y] = 0;
	}
}

int main(int argc, char* argv[]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				blanks[blank_size].x = i;
				blanks[blank_size++].y = j;
			}
		}
	}

	cout << '\n';
	dfs(0);

	return 0;
}