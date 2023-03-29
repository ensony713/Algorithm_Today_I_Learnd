#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	bool network[MAX][MAX] = { 0 };
	bool visite[MAX] = { 0 };
	vector<int> works;
	int n, m, a, b, tmp, result = 0;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		network[a][b] = true;
		network[b][a] = true;
	}

	works.push_back(1);

	while (!works.empty()) {

		tmp = works.front();
		works.erase(works.begin());
		visite[tmp] = true;

		for (int i = 1; i <= n; i++) {
			if (!visite[i] && network[tmp][i]) {
				works.push_back(i);
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (visite[i]) {
			result++;
		}
	}

	cout << result;

	return 0;
}