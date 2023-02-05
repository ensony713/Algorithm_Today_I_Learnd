#include <iostream>
#define MAX 100
using namespace std;

int main(int argc, char* argv[]) {
	bool canvas[MAX][MAX] = { 0 };
	int x, y, n, width = 0; 
	// n = 색종이 수  x = 색종이의 왼쪽 x 좌표   y = 색종이의 위쪽 y 좌표
	
	cin >> n;
	for (int i = 0; i < n; i++) { // n <= 100임
		cin >> x >> y;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				canvas[x + j][y + k] = true;
			}
		}
	}

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (canvas[i][j]) { width++; }
		}
	}

	cout << width;
	return 0;
}