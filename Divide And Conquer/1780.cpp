#include <iostream>
#define MAX 90
using namespace std;

class Divide_paper {
private:
	int N, paper[MAX][MAX] = { 0 };
	int result[3] = { 0 };
	bool is_all_same(int x, int y, int a, int & key) {
		key = paper[x][y];
		for (int i = x; i < x + a; i++) {
			for (int j = y; j < y + a; j++)
				if (paper[i][j] != key) return false;
		}
		return true;
	}
public:
	void set(int n) {
		N = n;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				cin >> paper[i][j];
		}
	}
	void divide(int x, int y, int a) {
		if (a == 1) {
			result[paper[x][y] + 1]++;
			return;
		}
		int value = -2, next = a / 3;
		if (is_all_same(x, y, a, value))
			result[value + 1]++;
		else {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					divide(x * next, y * next, next);
			}
		}
	}
	void print() {
		for (auto a : result)
			cout << a << "\n";
	}
};

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	Divide_paper paper;
	int tmp;
	cin >> tmp;
	paper.set(tmp);
	paper.divide(0, 0, tmp);
	paper.print();
	return 0;
}