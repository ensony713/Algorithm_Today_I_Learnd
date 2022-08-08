#include <iostream>
#include <map>
using namespace std;

int main(int argc, char* argv[]) {
	int t, n;
	long long result = 1;
	string category, name;
	map<string, int> clothes;

	// 각 독립 시행 (해당 카테고리의 옷 중 하나를 고르는 경우의 수) 들을 모두 곱해서 -1

	cin >> t;

	for (int tc = 0; tc < t; tc++) {

		clothes.clear();

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> name >> category;
			clothes[category]++;
		}

		result = 1;
		for (auto c : clothes) {
			result *= c.second + 1;
		}

		cout << result - 1 << '\n';
	}

	return 0;
}