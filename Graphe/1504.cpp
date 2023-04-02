#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

typedef struct node {
	long cost = 0; // 비용
	int idx = 0; // 연결된 정점
};

void dijikstra(vector<vector<node>>& gr, vector<long>& result , int start) {

	priority_queue<pair<long, int>> heap;
	// -가중치, 노드번호

	result[start] = 0;
	heap.push({ 0, start });

	while (!heap.empty()) {

		long cur_cost = -heap.top().first;
		int cur_idx = heap.top().second;
		heap.pop();

		if (cur_cost > result[cur_idx]) {
			continue;
		}

		for (auto& i : gr[cur_idx]) {

			if (cur_cost + i.cost < result[i.idx]) {
				result[i.idx] = cur_cost + i.cost;
				heap.push({ -result[i.idx], i.idx });
			}
		}
	}
}

int main(long argc, char** argv) {

	vector<vector<node>> graphe;
	vector<long> result;
	long one2u, one2v, u2v, v2u, u2n, v2n, output = -1;
	int N, E, a, b, c, u, v;
	node input;
	cin >> N >> E;

	graphe.resize(N + 1);
	result.resize(N + 1, numeric_limits<long>::max());

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		
		input.cost = c;
		input.idx = b;
		graphe[a].push_back(input);

		input.idx = a;
		graphe[b].push_back(input);
	}

	cin >> u >> v;

	dijikstra(graphe, result, 1);
	one2u = result[u];
	one2v = result[v];

	result.clear();
	result.resize(N + 1, numeric_limits<long>::max());
	dijikstra(graphe, result, u);
	u2n = result[N];
	u2v = result[v];

	result.clear();
	result.resize(N + 1, numeric_limits<long>::max());
	dijikstra(graphe, result, v);
	v2n = result[N];
	v2u = result[u];

	if (one2u < numeric_limits<long>::max() && u2v < numeric_limits<long>::max() && v2n < numeric_limits<long>::max()) {
		output = one2u + u2v + v2n;
	}
	
	if (one2v < numeric_limits<long>::max() && v2u < numeric_limits<long>::max() && u2n < numeric_limits<long>::max()) {
		output = output < one2v + v2u + u2n ? output : one2v + v2u + u2n;
	}

	cout << output;
	
	return 0;
}