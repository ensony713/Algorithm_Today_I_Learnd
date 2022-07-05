#include <iostream>
#include <string>
using namespace std;

int n, m;
char board[55][55];
string input;

class ChessBoard {
private:
	char board[8][8];
	int counter = 0;
	
public:
	void initCounter() {
		counter = 0;
	}

	void switching() {
		counter++;
		board[0][0] = board[0][0] == 'B' ? 'W' : 'B';
	}

	void cut(int x, int y, char b[55][55]) {
		for (int i = x; i < x + 8; i++) {
			for (int j = y; j < y + 8; j++) {
				board[i - x][j - y] = b[i][j];
			}
		}
	}

	int count() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (!checkPoint(i, j)) { counter++; }
			}
		}

		return counter;
	}

	bool checkPoint(int x, int y) {
		bool check = true;

		if (x != 0 && board[x - 1][y] == board[x][y]) {
			board[x][y] = board[x][y] == 'B' ? 'W' : 'B';
			check = false;
		}
		if (y != 0 && board[x][y - 1] == board[x][y]) {
			board[x][y] = board[x][y] == 'B' ? 'W' : 'B';
			check = false;
		}

		return check;
	}
};

int main() {
	ChessBoard cb;
	int mini = 65, origin, switching;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < m; j++) {
			board[i][j] = input[j];
		}
	}

	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			cb.cut(i, j, board);
			origin = cb.count();
			mini = mini > origin ? origin : mini;
			cb.initCounter();

			cb.cut(i, j, board);
			cb.switching();
			switching = cb.count();
			mini = mini > switching ? switching : mini;
			cb.initCounter();
		}
	}
	cout << mini;

	return 0;
}