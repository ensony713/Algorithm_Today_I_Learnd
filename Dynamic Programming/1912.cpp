#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, maxi = -1000;
	int* num = new int[100004]{ 0 };
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	maxi = num[0];
	for (int i = 1; i < n; i++) {
		num[i] = num[i] > num[i - 1] + num[i] ? num[i] : num[i - 1] + num[i];
		maxi = maxi > num[i] ? maxi : num[i];
	}

	cout << maxi;

	delete[] num;
	return 0;
}