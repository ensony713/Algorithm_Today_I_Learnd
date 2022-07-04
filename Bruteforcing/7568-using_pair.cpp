#include <iostream>
#include <utility>
using namespace std;

int main() {
	pair<int, int> body[50];
	int n, x, y, counter = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		body[i] = make_pair(x, y);
	}

	for (int i = 0; i < n; i++) {
		counter = 0;
		for (int j = 0; j < n; j++) {
			if (body[i].first < body[j].first && body[i].second < body[j].second) {
				counter++;
			}
		}
		cout << ++counter << ' ';
	}
	return 0;
}