#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	int t, input, maxi = 0, mini = 2000000;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> input;
		maxi = maxi < input ? input : maxi;
		mini = mini > input ? input : mini;
	}

	cout << maxi * mini;

	return 0;
}