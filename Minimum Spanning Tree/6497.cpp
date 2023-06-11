#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;

struct node {
	int a, b;
	int weight;
};

class UnionFind {

	int root[MAX];
	int size;

public:

	UnionFind(int n) {
		
		size = n;

		for (int i = 0; i < n; i++) {
			root[i] = i;
		}
	}

	int find(int a) {

		if (root[a] == a) { return a; }

		root[a] = find(root[a]);

		return root[a];
	}

	void combin(int a, int b) {

		if (is_union(a, b)) { return; }

		int ra = find(a);
		int rb = find(b);

		if (ra < rb) {
			root[rb] = ra;
		}
		else {
			root[ra] = rb;
		}
	}

	bool is_union(int a, int b) {

		if (find(a) == find(b)) { return true; }
		return false;
	}
};

bool sorted(node a, node b) {
	if (a.weight <= b.weight) { return false; }
	return true;
}

int kruskal(vector<node>& roads, int m) {

	int result = 0;
	UnionFind uf(m);
	sort(roads.begin(), roads.end(), sorted);
	
	while (!roads.empty()) {

		node now = roads.back();
		roads.pop_back();

		if (uf.is_union(now.a, now.b)) {
			result += now.weight;
			continue;
		}

		uf.combin(now.a, now.b);
	}

	return result;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, x, y, z;
	vector<node> roads;
	node input;
	
	while (true) {
		cin >> n >> m;

		if (n == 0 && m == 0) {
			return 0;
		}

		roads.clear();

		for (int i = 0; i < m; i++) {

			cin >> x >> y >> z;
			input.a = x;
			input.b = y;
			input.weight = z;

			roads.push_back(input);
		}

		cout << kruskal(roads, m) << "\n";
	}

	return 0;
}