#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, bool> words;
	string input;
	int N, M, count = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> input;
		words.insert(make_pair(input, true));
	}

	for (int i = 0; i < M; i++) {
		cin >> input;

		if (words[input]) {
			count++;
		}
	}

	cout << count;

	return 0;
}