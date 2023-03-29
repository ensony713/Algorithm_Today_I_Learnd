#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

void dfs(vector<int>& list, bool matrix[][MAX], bool visite[], int idx, int n) {

	if (idx > n) {
		return;
	}
	
	visite[idx] = true;
	list.push_back(idx);

	for (int i = 1; i <= n; i++) {
		if (matrix[idx][i] && !visite[i]) {
			dfs(list, matrix, visite, i, n);
		}
	}
}

void bfs(vector<int>& list, bool matrix[][MAX], int n, int start) {

	vector<int> idx;
	int tmp;
	bool visite[MAX] = { 0 };

	idx.push_back(start);
	visite[start] = true;

	while(!idx.empty()) {
		
		tmp = idx.front();
		idx.erase(idx.begin());
		list.push_back(tmp);

		for (int i = 1; i <= n; i++) {
			if (!visite[i] && matrix[tmp][i]) {
				idx.push_back(i);
				visite[i] = true;
			}
		}
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	bool matrix[MAX][MAX] = { 0 };
	bool visite[MAX] = { 0 };
	vector<int> resultD, resultB;
	int n, m, v, a, b;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		matrix[a][b] = true;
		matrix[b][a] = true;
	}

	dfs(resultD, matrix, visite, v, n);

	for (auto& a : resultD) {
		cout << a << ' ';
	}
	cout << '\n';

	bfs(resultB, matrix, n, v);

	for (auto& a : resultB) {
		cout << a << ' ';
	}
	cout << '\n';

	return 0;
}