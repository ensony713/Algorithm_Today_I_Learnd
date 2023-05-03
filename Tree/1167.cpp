#include <iostream>
#include <vector>
#include <queue>
#define MAX 100
using namespace std;

void dfs(int idx, bool visite[], vector<vector<pair<int, int>>>& tree, vector<int>& sum) {

	visite[idx] = true;

	for (auto& i : tree[idx]) {
		int now = i.first;

		if (!visite[now]) {
			sum[now] = sum[idx] + i.second;
			dfs(now, visite, tree, sum);
		}
	}
}

int main(int argc, char** argv) {

	int v, a, b = 0, cost, mid = 0, last = 0, result1 = 0, result2 = 0;
	vector<vector<pair<int, int>>> tree;
	vector<int> sum;
	bool visite1[MAX] = { 0 };
	bool visite2[MAX] = { 0 };

	cin >> v;
	tree.resize(v + 1);

	for (int i = 1; i <= v; i++) {
		cin >> a;

		cin >> b;
		while (b != -1) {
			cin >> cost;
			tree[a].push_back({b, cost});
			cin >> b;
		}
	}

	sum.resize(v + 1, 0);
	dfs(1, visite1, tree, sum);
	for (int i = 1; i <= v; i++) {
		if (result1 < sum[i]) {
			result1 = sum[i];
			mid = i;
		}
	}

	sum.clear();
	sum.resize(v + 1, 0);
	dfs(mid, visite2, tree, sum);
	for (int i = 1; i <= v; i++) {
		if (result2 < sum[i]) {
			result2 = sum[i];
			last = i;
		}
	}

	cout << 1 << " " << mid << " " << last << '\n';
	cout << result1 << ' ' << result2 << '\n';
	
	cout << (result1 < result2 ? result2 : result1);

	return 0;
}