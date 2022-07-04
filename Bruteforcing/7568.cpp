#include <iostream>
using namespace std;

void bigger(int N, int human[][2], int lank[], int num);

int main() {
	int human[50][2], lank[50], N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> human[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		bigger(N, human, lank, i);
	}

	for (int i = 0; i < N; i++) {
		cout << lank[i] << " ";
	}
}

void bigger(int N, int human[][2], int lank[], int num) {
	int weight = human[num][0], height = human[num][1], n = 1;

	for (int i = 0; i < N; i++) {
		if (weight < human[i][0] && height < human[i][1]) {
			n++;
		}
	}

	lank[num] = n;
}