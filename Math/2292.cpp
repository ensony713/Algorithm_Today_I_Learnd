#include <iostream>
using namespace std;

int main() {
	long long N;
	int index = 1, i;
	
	cin >> N;

	for (i = 1; N > index; i++) {
		index += 6 * i;
	}
	cout << i;
}