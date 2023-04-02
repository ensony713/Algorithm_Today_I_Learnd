#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#define MAX 20
using namespace std;

typedef struct point {
	int idx;
	int value;
};

void dijkstra(vector<vector<point>>& gr, int start, vector<int>& result) {

	int distance;
	priority_queue<pair<int, int>> heap;

	result[start] = 0;
	heap.push({ start, 0 });

	while (!heap.empty()) {

		int cur_idx = heap.top().first;
		int cur_cost = heap.top().second;
		heap.pop();

		if (cur_cost > result[cur_idx]) {
			continue;
		}

		for (auto& n : gr[cur_idx]) {
			distance = cur_cost + n.value;

			if (distance < result[n.idx]) {
				result[n.idx] = distance;
				heap.push({ n.idx, distance });
			}
		}
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int K, V, E, u, v, w;
	point tmp;
	vector<vector<point>> graphe;
	vector<int> result;
	cin >> V >> E >> K;

	result.resize(V + 1, numeric_limits<int>::max());
	graphe.resize(V + 1);

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;

		tmp.idx = v;
		tmp.value = w;
		graphe[u].push_back(tmp);
	}

	dijkstra(graphe, K, result);

	for (int i = 1; i <= V; i++) {
		
		if (result[i] == numeric_limits<int>::max()) {
			cout << "INF\n";
		}
		else {
			cout << result[i] << '\n';
		}
	}

	return 0;
}