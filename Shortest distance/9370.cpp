#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

typedef struct node {
	int idx;
	int cost = numeric_limits<int>::max();
};

void dijikstra(vector<vector<node>>& gr, int start, vector<int>& result) {

	priority_queue<pair<int, int>> heap;
	// -cost, index

	heap.push({ 0, start });
	result[start] = 0;

	while (!heap.empty()) {

		int cost = -heap.top().first;
		int idx = heap.top().second;

		heap.pop();

		if (cost > result[idx]) {
			continue;
		}

		for (auto& l : gr[idx]) {
			if (result[l.idx] > l.cost + cost) {
				result[l.idx] = l.cost + cost;
				heap.push({ -result[l.idx], l.idx });
			}
		}
	}
}

int main(int argc, char** argv) {

	vector<vector<node>> graphe;
	vector<int> result;
	node input;

	int s2h, s2g, g2h, h2g, shgd = -1, sghd = -1, sum;
	node g2d[105], h2d[105];
	int n, m, t, s, g, h, a, b, d, T;
	vector<int> dest;

	cin >> T;
	
	while (T--) {

		cin >> n >> m >> t;
		cin >> s >> g >> h;

		graphe.resize(n + 1);
		result.resize(n + 1, numeric_limits<int>::max());

		for (int i = 0; i < m; i++) {
			cin >> a >> b >> d;

			input.idx = b;
			input.cost = d;
			graphe[a].push_back(input);

			input.idx = a;
			graphe[b].push_back(input);
		}

		for (int i = 0; i < t; i++) {
			cin >> d;
			dest.push_back(d);
		}
		sort(dest.begin(), dest.end());

		// 각 위치에서 거리 구하기
		dijikstra(graphe, h, result);
		for (auto& i : dest) {
			h2d[i].idx = i;
			h2d[i].cost = result[i];
		}
		h2g = result[g];

		result.clear();
		result.resize(n + 1, numeric_limits<int>::max());
		dijikstra(graphe, g, result);
		for (auto& i : dest) {
			g2d[i].idx = i;
			g2d[i].cost = result[i];
		}
		g2h = result[h];

		result.clear();
		result.resize(n + 1, numeric_limits<int>::max());
		dijikstra(graphe, s, result);
		s2h = result[h];
		s2g = result[g];

		for (auto& i : dest) {

			shgd = -1;
			if (s2h < numeric_limits<int>::max() && h2g < numeric_limits<int>::max() && g2d[i].cost < numeric_limits<int>::max()) {
				shgd = s2h + h2g + g2d[i].cost;
			}

			sghd = -1;
			if (s2h < numeric_limits<int>::max() && g2h < numeric_limits<int>::max() && h2d[i].cost < numeric_limits<int>::max()) {
				sghd = s2g + g2h + h2d[i].cost;
			}

			sum = -1;
			if (sghd == -1) {
				sum = sghd;
			}
			else if (shgd == -1) {
				sum = shgd;
			}
			else {
				sum = shgd < sghd ? shgd : sghd;
			}

			if (sum != -1 && result[i] == sum) {
				cout << i << " ";
			}
			
		}
		
		cout << '\n';
		graphe.clear();
		dest.clear();
		result.clear();
	}

	return 0;
}