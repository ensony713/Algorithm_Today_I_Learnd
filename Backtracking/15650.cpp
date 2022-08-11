#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visited[10] = { 0 };
vector <int> result;

void permutation(int deep) {
	if (deep >= m) {
		for (auto v : result) {
			cout << v << " ";
		}
		cout << '\n';
		return;
	}

	int start = result.size() == 0 ? 1 : result[result.size() - 1];

	for (int i = start; i <= n; i++) {
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