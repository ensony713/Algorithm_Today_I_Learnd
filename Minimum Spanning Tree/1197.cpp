#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;

typedef long long number;

struct Node {
	long weight;
	int node1;
	int node2;
};

class MinHeap {
	Node data[MAX] = { 0 };
	int size = 0;

public:

	void insert(Node n) {
		
		data[++size] = n;

		for (int i = size; i > 1; i = i / 2) {
			if (data[i].weight < data[i / 2].weight) {
				swap(data[i], data[i / 2]);
			}
			else { break; }
		}
	}

	Node remove() {
		
		Node mini;
		mini.node1 = 0;
		mini.node2 = 0;
		mini.weight = 0;

		if (size == 0) { return mini; }

		mini = data[1];
		int idx = 1, l, r;
		data[1] = data[size--];

		for (int i = 1; i <= size;) {

			l = i * 2;
			r = i * 2 + 1;

			if (l <= size && r <= size) {
				idx = data[l].weight < data[r].weight ? l : r;
			}
			else if (l <= size) {
				idx = l;
			}
			else if (r <= size) {
				idx = r;
			}

			if (data[idx].weight < data[i].weight) {
				swap(data[idx], data[i]);
				i = idx;
			}
			else { break; }
		}

		return mini;
	}

	bool empty() {
		if (size == 0) { return true; }
		return false;
	}
};

class UnionSet {

	int root[MAX];

public:

	int get_root(int a) {
		return root[a];
	}

	UnionSet(int n) {

		for (int i = 1; i <= n; i++) {
			root[i] = i;
		}
	}

	void combin(int a, int b) {

		a = find(a);
		b = find(b);

		if (a == b) { return; }

		if (a < b) {
			root[b] = a;
		}
		else {
			root[a] = b;
		}
	}

	bool is_union(int a, int b) {

		int pa = find(a);
		int pb = find(b);

		return pa == pb;
	}

	int find(int a) {

		if (root[a] != a) {
			root[a] = find(root[a]);
		}

		return root[a];
	}
};

number mini_spanning_tree(int v, int e, MinHeap& edge) {

	number result = 0;
	UnionSet un(v);

	while (!edge.empty()) {

		Node now = edge.remove();
		
		if (un.is_union(now.node1, now.node2)) {
			continue;
		}

		un.combin(now.node1, now.node2);
		result += now.weight;
	}

	return result;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int v, e, a, b;
	long c;
	Node input;
	MinHeap edge;

	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		input.weight = c;
		input.node1 = a;
		input.node2 = b;

		edge.insert(input);
	}

	cout << mini_spanning_tree(v, e, edge);

	return 0;
}