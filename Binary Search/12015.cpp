#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

vector<int> lis;
int a[MAX];

int binarySearch(int n, int num) {

	int small = 0, large = lis.size(), mid = 0;

	while (small < large) {
		
		mid = (large + small) / 2;

		if (lis[mid] < a[num]) {
			small = mid + 1;
		}
		else {
			large = mid;
		}
	}

	return small;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, index;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	lis.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		index = binarySearch(n, i);
		if (index >= lis.size()) {
			lis.push_back(a[i]);
		}
		else {
			lis[index] = a[i];
		}
	}

	cout << lis.size();

	return 0;
}