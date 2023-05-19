#include <iostream>
#include <vector>
#define MAX 1003
using namespace std;

class UnionFind {

	int root[MAX] = { 0 };

public:
	
	UnionFind(int n) {
		for (int i = 0; i < n; i++) {
			root[i] = i;
		}
	}

	int find(int a) {

		if (root[a] != a) {
			root[a] = find(root[a]);
		}

		return root[a];
	}

	bool is_union(int a, int b) {

		int pa = find(a);
		int pb = find(b);

		return pa == pb;
	}

	void combin(int a, int b) {

		int pa = find(a);
		int pb = find(b);

		if (pa < pb) {
			root[pb] = pa;
		}
		else {
			root[pa] = pb;
		}
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, a, b, result = 0;
	cin >> n >> m;

	UnionFind uf(n);

	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		
		if (result == 0 && uf.is_union(a, b)) {
			result = i;
		}
		else {
			uf.combin(a, b);
		}
	}

	cout << result;
	return 0;
}