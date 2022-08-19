#include <iostream>
using namespace std;

int rc = 0, dp = 0;
unsigned int memory[42] = { 0 };

int fib(int n) {
	if (n == 1 || n == 2) {
		rc++;
		return 1; 
	}
	else { return fib(n - 1) + fib(n - 2); }
}

int fibonacci(int n) {
	
	memory[1] = 1;	memory[2] = 1;

	for (int i = 3; i <= n; i++) {
		dp++;
		memory[i] = memory[i - 1] + memory[i - 2];
	}

	return memory[n];
}

int main(int argc, char* argv) {
	int n;
	cin >> n;

	fib(n);
	fibonacci(n);

	cout << rc << " " << dp << '\n';
	return 0;
}