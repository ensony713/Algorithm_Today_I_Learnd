#include <iostream>
#include <vector>
using namespace std;

int stroke[] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

int main(int argc, char** argv) {
	string name1, name2;
	vector<int> cb;

	cin >> name1 >> name2;

	for (int i = 0; i < name1.size(); i++) {
		cb.push_back(stroke[name1[i] - 'A']);
		cb.push_back(stroke[name2[i] - 'A']);
	}

	vector<int> result;
	while (true) {

		result.clear();

		for (int i = 0; i < cb.size() - 1; i++) {
			result.push_back((cb[i] + cb[i + 1]) % 10);
		}

		cb = result;
		if (result.size() <= 2) {
			break;
		}
	}

	for (auto& a : cb) {
		cout << a;
	}

	return 0;
}