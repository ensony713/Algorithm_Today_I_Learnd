#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visited[10] = { 0 };
vector <int> result;

// 왜 결국 dfs가 될까?
void permutation(int deep) {
	if (deep >= m) {
		for (auto v : result) {
			cout << v << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			result.push_back(i);
			permutation(deep + 1);
			visited[i] = false;
			result.pop_back();
		}
	}
}

int main(int argc, char* argv[]) {

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}

	permutation(0);

	return 0;
}