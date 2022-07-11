#include <iostream>
#define MAX 101
using namespace std;

class Surface {
private:
	int n; // 삼성국의 길이
	int area;
	int dx[4] = { 0, 1, -1, 0 }, 
		dy[4] = { 1, 0, 0, -1 };
	int world[MAX][MAX] = { 0 }; // 삼성국의 칸 별 높이
	bool flooding[MAX][MAX] = { 0 }; // 각 칸의 침수 여부
	bool visited[MAX][MAX] = { 0 };

public:
	Surface() {
		area = 0;
	}

	void set() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> world[i][j];
			}
		}
	}

	void init() {
		area = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				flooding[i][j] = 0;
				visited[i][j] = 0;
			}
		}
	}

	void dfs(int x, int y) {
		
		visited[x][y] = true;

		for (int i = 0; i < 4; i++) {
			
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= n || ny >= n || nx < 0 || ny < 0) { continue; }

			if (!visited[nx][ny] && !flooding[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}

	int countArea() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == 0 && !flooding[i][j]) {
					dfs(i, j);
					area++;
				}
			}
		}

		return area;
	}

	void flood(int h) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (world[i][j] <= h) {
					flooding[i][j] = true;
				}
			}
		}
	}

	void printflood() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!flooding[i][j]) {
					cout << world[i][j] << ' ';
				}
				else {
					cout << "  ";
				}
			}
			cout << '\n';
		}
	}

	int getArea() { return area; }
	int getN() { return n; }
};

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	Surface sf;
	int t, // 테스트 케이스 수
		n, c = 0,
		max = 0, // 출력할 최대값
		tmp; // 임시 저장
	
	cin >> t;

	while(c++ < t) {
		max = 0;

		sf.set();

		n = sf.getN();

		for (int i = 0; i < MAX; i++) {
			sf.flood(i);
			tmp = sf.countArea();
			max = tmp > max ? tmp : max;
			sf.init();
		}

		cout << "#" << c << " " << max << '\n';
	}

	return 0;
}