#include <iostream>
#include <string>
#define MAX 65
using namespace std;

class Quad_Tree {
private:
	int board[MAX][MAX] = { 0 }, N = 0;
	string input;

	bool is_same(int x, int y, int a, int & value) {
		// x, y부터 한 변의 길이가 a인 정사각형 범위 안이 모두 같은지 확인
		value = board[x][y];
		for (int i = x; i < x + a; i++) {
			for (int j = y; j < y + a; j++) {
				if (board[i][j] != value) {
					return false;
				}
			}	
		}
		return true;
	}

public:
	void get(int n) {
		N = n;
		for (int i = 0; i < N; i++) {
			cin >> input;
			for (int j = 0; j < N; j++)
				board[i][j] = int(input[j]) - 48;
		}
	}
	void compress(int x, int y, int a) {

		if (a == 1) {
			cout << board[x][y];
			return;
		}
		int new_a = a / 2, value = -1;
		if (is_same(x, y, a, value)) {
			cout << value;
		}
		else {
			cout << "(";
			compress(x, y, new_a);
			compress(x, y + new_a, new_a);
			compress(x + new_a, y, new_a);
			compress(x + new_a, y + new_a, new_a);
			cout << ")";
		}
	}
	void show_all() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
	}
};

Quad_Tree qt;
int num;

int main() {
	cin >> num;
	qt.get(num);
	qt.compress(0, 0, num);
	return 0;
}