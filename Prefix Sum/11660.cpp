#include <iostream>
#define MAX 1030
using namespace std;

struct Point {
	int x, y;
};

int table[MAX][MAX] = { 0 };

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, result = 0;
	Point start, end;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> table[i][j];
			table[i][j] += table[i][j - 1];
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> start.x >> start.y >> end.x >> end.y;
		result = 0;

		for (int j = start.x; j <= end.x; j++) {
			result += table[j][end.y] - table[j][start.y - 1];
		}

		cout << result << '\n';
	}

	return 0;
}