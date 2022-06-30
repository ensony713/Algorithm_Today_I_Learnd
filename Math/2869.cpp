#include <iostream>
using namespace std;

int main() {
	double a, b, v, result;
	int output = 0;


	cin >> a >> b >> v;
	result = (v - a) / (a - b) + 1;
	
	output = (int)result;
	if (result > (int)result) {
		output++;
	}

	cout << output;

	return 0;
}