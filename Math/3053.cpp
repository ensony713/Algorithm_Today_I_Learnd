#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]) {
	double r;
	const double PI = acos(-1);

	cin >> r;

	cout << fixed;
	cout.precision(6);
	cout << r * r * PI << '\n';
	cout << r * r * 2 << '\n';

	return 0;
}