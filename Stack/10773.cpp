#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, sum = 0, k;
	vector<int> list;
	
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> input;
		
		if (!input) {
			list.pop_back();
		}
		else {
			list.push_back(input);
		}
	}

	for (auto a : list) {
		sum += a;
	}

	cout << sum;
	return 0;
}