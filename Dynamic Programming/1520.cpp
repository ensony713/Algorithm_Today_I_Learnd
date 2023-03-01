#include <iostream>
#include <memory.h>
#define MAX 505
using namespace std;

typedef long long num;

num cache[MAX][MAX] = { 0 };
int map[MAX][MAX] = { 0 };
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

num dfs(int x, int y, int n, int m) {
	
	if (x == n && y == m) {
		return 1;
	}

	if (cache[x][y] != -1) {
		return cache[x][y];
	}

	int nx, ny;
	cache[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		nx = dx[i] + x;
		ny = dy[i] + y;

		if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
			// 좌표가 map 상의 유효한 위치에 있는지 확인

			if ( map[nx][ny] < map[x][y]) {
				cache[x][y] += dfs(nx, ny, n, m);
			}
		}
	}

	return cache[x][y];
}

int main(int argc, char** argv) {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	memset(cache, -1, sizeof(cache));
	// 갈 수 없어서 0인 부분과 탐색하지 않은 부분을 구분하기 위해 전부 -1로 세팅

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	cout << dfs(1, 1, n, m);
	
	return 0;
}