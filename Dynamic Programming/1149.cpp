#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, price[3][1005] = { 0 }, mini = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> price[0][i] >> price[1][i] >> price[2][i];
	}

	for (int i = 1; i < n; i++) {
		price[0][i] = price[1][i - 1] < price[2][i - 1] ?
			price[0][i] + price[1][i - 1] : price[0][i] + price[2][i - 1];
		
		price[1][i] = price[0][i - 1] < price[2][i - 1] ?
			price[1][i] + price[0][i - 1] : price[1][i] + price[2][i - 1];
		
		price[2][i] = price[1][i - 1] < price[0][i - 1] ?
			price[2][i] + price[1][i - 1] : price[2][i] + price[0][i - 1];
	}

	mini = price[0][n - 1];
	mini = mini < price[1][n - 1] ? mini : price[1][n - 1];
	mini = mini < price[2][n - 1] ? mini : price[2][n - 1];

	cout << mini;
	return 0;
}