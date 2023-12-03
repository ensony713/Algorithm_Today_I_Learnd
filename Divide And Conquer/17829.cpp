#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 2000;
const int MIN = -20000;
int matrix[MAX][MAX] = { 0 };

void show(int n) {

	cout << '\n'; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

// 2X2 행렬에서 두번째로 큰 수 찾기
int second_largest(int a, int b, int c, int d) {
	
	int arr[] = { a, b, c, d }, large = a, second = MIN;

	for (int i = 1; i < 4; i++) {
		if (arr[i] > large) {
			second = large;
			large = arr[i];
		}
		else {
			second = second < arr[i] ? arr[i] : second;
		}
	}

	return second;
}

void solution(int n) {
	
	if (n / 2 < 1) {
		return ;
	}

	int di = 0, dj = 0;

	// 두번째로 큰 값 찾아서 행렬 압축하기
	for (int i = 0; i < n; i += 2) {
		for (int j = 0; j < n; j += 2) {
			matrix[di][dj++] = second_largest(
				matrix[i][j],
				matrix[i][j + 1],
				matrix[i + 1][j],
				matrix[i + 1][j + 1]
			);
		}
		di++;
		dj = 0;
	}

	show(n / 2);

	solution(n / 2);
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n, input;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	solution(n);

	cout << matrix[0][0];

	return 0;
}