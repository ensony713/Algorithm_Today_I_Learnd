#include <iostream>
#define MAX 10
using namespace std;

int main(int argc, char* argv[]) {
	int maximum = 0, x = 0, y = 0;
	int matrix[MAX][MAX] = { 0 };

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> matrix[i][j];
			if (maximum <= matrix[i][j]) {
				maximum = matrix[i][j];
				x = i + 1;
				y = j + 1;
			}
		}
	}

	cout << maximum << '\n' << x << ' ' << y;

	return 0;
}