#include <iostream>
#include <map>
using namespace std;

int main(int argc, char* argv[]) {
	int t, n;
	long long result = 1;
	string category, name;
	map<string, int> clothes;

	// �� ���� ���� (�ش� ī�װ��� �� �� �ϳ��� ���� ����� ��) ���� ��� ���ؼ� -1

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