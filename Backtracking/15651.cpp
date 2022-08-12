#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> result;

void pie(int deep) {
	if (deep >= m) {
		for (auto v : result) {
			cout << v << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		result.push_back(i);
		pie(deep + 1);
		result.pop_back();
	}
}

int main(int argc, char* argv[]) {
	cin >> n >> m;

	pie(0);

	return 0;
}