#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	map<int, bool> hand_card;
	int N, input, M;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		hand_card.insert(make_pair(input, true));
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> input;
		if (hand_card[input]) { cout << 1 << " "; }
		else { cout << 0 << " "; }
	}

	return 0;
}