#include <iostream>
#include <vector>
using namespace std;

int N, tmp;
vector<int> que;

int main() {
	cin >> N;

	for (int i = N; i > 0; i--)
		que.push_back(i);

	while (que.size() > 1) {
		que.pop_back();
		tmp = que[que.size() - 1];
		que.pop_back();
		que.insert(que.begin(), tmp);
	}
	cout << que[0] << "\n";
	return 0;
}