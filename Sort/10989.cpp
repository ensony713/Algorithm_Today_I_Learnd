#include <iostream>
#define SCOPE 10000
using namespace std;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, num, count[SCOPE] = { 0 }, max = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		max = max < num ? num : max;
		count[num]++;
	}

	cout << '\n';
	for (int i = 0; i <= max; i++) {
		for (int j = 0; j < count[i]; j++) {
			cout << i << '\n';
		}
	}

	return 0;
}