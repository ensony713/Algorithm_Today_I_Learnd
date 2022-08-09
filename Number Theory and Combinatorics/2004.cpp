#include <iostream>
using namespace std;

typedef unsigned long long number;

number number0(int n, int d) {
	number result = 0;

	for (number i = d; i <= n; i *= d) {
		result += n / i;
	}

	return result;
}

int main(int argc, char* argv[]) {

	number n, m, two, five;
	cin >> n >> m;

	two = number0(n, 2) - number0(m, 2) - number0(n - m, 2);
	five = number0(n, 5) - number0(m, 5) - number0(n - m, 5);

	cout << (two < five ? two : five) << '\n';
	
	return 0;
}