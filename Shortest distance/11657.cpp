#include <iostream>
#include <vector>
#include <limits>
using namespace std;

typedef long long num;

typedef struct node {
	int start;
	int dest;
	num cost;
};

bool bellman_ford(vector<node>& gr, vector<num>& result, int start, int n) {

	result.clear();
	result.resize(n + 1, numeric_limits<num>::max());
	// 결과값을 INF로 채움
	result[start] = 0;
	// 시작점의 비용은 0

	// 노드의 개수만큼 반복
	for (int i = 1; i <= n; i++) {

		// 한 반복에 모든 간선을 확인
		for (auto& a : gr) {

			if (result[a.start] != numeric_limits<num>::max() && result[a.dest] > result[a.start] + a.cost) {
				result[a.dest] = result[a.start] + a.cost;

				if (i == n) { return true; }
			}
		}
	}

	return false;
}

int main(int argc, char** argv) {

	vector<node> graphe;
	vector<num> result;
	node input;
	int n, m, a, b;
	num c;
	cin >> n >> m;

	graphe.resize(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		input.start = a;
		input.dest = b;
		input.cost = c;
		graphe.push_back(input);
	}

	if (bellman_ford(graphe, result, 1, n)) {
		cout << -1 << '\n';
		return 0;
	}

	for (int i = 2; i <= n; i++) {
		if (result[i] == numeric_limits<num>::max()) {
			cout << -1 << '\n';
		}
		else {
			cout << result[i] << '\n';
		}
	}

	return 0;
}