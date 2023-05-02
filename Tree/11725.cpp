#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

void dfs(int idx, int n, bool visite[], vector<vector<int>>& tree, int list[]) {

	if (idx > n) { return; }

	visite[idx] = true;

	for (auto & i : tree[idx]) {
		if (!visite[i]) {
			list[i] = idx;
			dfs(i, n, visite, tree, list);
		}
	}
}

int main(int argc, char** argv) {
	
	int n, a, b;
	vector<vector<int>> tree;
	int list[MAX] = { 0 };
	bool visite[MAX] = { 0 };

	cin >> n;

	tree.resize(n + 1);

	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1, n, visite, tree, list);

	for (int i = 2; i <= n; i++) {
		cout << list[i] << '\n';
	}

	return 0;
}