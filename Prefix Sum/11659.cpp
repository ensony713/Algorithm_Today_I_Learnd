#include <iostream>
using namespace std;

int arr[100003] = { 0 };

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int start, end, result;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		
		cout << arr[end] - arr[start - 1] << '\n';
	}

	return 0;
}