#include <iostream>
#define MAX 30
using namespace std;

int dx[] = { 0, 1, -1, 0 };
int dy[] = { 1, 0, 0, -1 };

int dfs(bool visite[], char board[][MAX], int r, int c, int x, int y) {

	if (x < 0 || x >= r || y < 0 || y >= c) {
		return 0;
	}

	int maxi = 0, move;
	
	for (int i = 0; i < 4; i++) {
		if (!visite[board[x + dx[i]][y + dy[i]] - 'A']) {
			visite[board[x + dx[i]][y + dy[i]] - 'A'] = true;

			move = dfs(visite, board, r, c, x + dx[i], y + dy[i]);
			maxi = move > maxi ? move : maxi;

			visite[board[x + dx[i]][y + dy[i]] - 'A'] = false;
		}
	}

	return maxi + 1;
}

int main(int argc, char** argv) {
	int r, c;
	string input;
	char board[MAX][MAX] = { 0 };
	bool visite[MAX] = { 0 };

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		cin >> input;
		for (int j = 0; j < c; j++) {
			board[i][j] = input[j];
		}
	}

	visite[board[0][0] - 'A'] = true;
	cout << dfs(visite, board, r, c, 0, 0) << '\n';

	return 0;
}