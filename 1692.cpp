#include <iostream>
using namespace std;

long long A, B, C;

long long pow(long long b) {
	if (b == 0) return 1;
	
	long long tmp = pow(b / 2) % C;
	if ((b % 2) == 0)
		return tmp % C * tmp % C;
	else
		return tmp % C * tmp % C * (A % C) % C;
}

int main() {
	cin >> A >> B >> C;
	cout << pow(B) << "\n";
	return 0;
}