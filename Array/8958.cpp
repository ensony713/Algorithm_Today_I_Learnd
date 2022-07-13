#include <iostream>
using namespace std;

int main() {
	int T, result, point;
	string answer;
	bool before = false;
	
	cin >> T;

	while (T-- != 0) {
		result = 0;
		point = 1;
		before = false;

		cin >> answer;

		for (auto i : answer) {
			if (i == 'O' && before) {
				result += ++point;
			}
			else if (i == 'O') {
				before = true;
				result += point;
			}
			else {
				before = false;
				point = 1;
			}
		}

		cout << result << '\n';
	}

	return 0;
}