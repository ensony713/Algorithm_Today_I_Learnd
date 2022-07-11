#include <iostream>
using namespace std;

int main() {
	int N, counter[11] = { 0 }, n = 0;
	cin >> N;

	for (int i = 1; i <= 1000000000; i = i * 10) {
		if (i > N) break; 
		counter[(N / i) % 10]++;
		n++;
	}
	
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < counter[i]; j++) {
			cout << i;
		}
	}

	return 0;
}