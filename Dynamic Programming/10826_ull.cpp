#include <iostream>
#define CIPHER 120
#define MAX 10000
using namespace std;

typedef unsigned long long Num;

typedef struct BigNumber {
	Num slice = 1000000000000000000;
	Num data[CIPHER] = { 0 };
	int size = 0;
};

BigNumber cache[MAX];
BigNumber zero;

BigNumber sum(const BigNumber& a, const BigNumber& b) {

	BigNumber result;
	int ssize = min(a.size, b.size);
	int lsize = max(a.size, b.size);
	Num carry = 0, sum;
		
	for (int i = 0; i < ssize; i++) {
		
		sum = a.data[i] + b.data[i] + carry;
		carry = sum / a.slice;
		
		result.data[i] = sum % a.slice;
	}

	for (int i = ssize; i < lsize; i++) {

		sum = a.data[i] + b.data[i] + carry;
		carry = sum / a.slice;

		result.data[i] = sum % a.slice;
	}

	result.size = lsize;
	if (carry > 0) {
		result.data[result.size++] = carry;
	}

	return result;
}

void show(BigNumber& a) {

	for (int i = a.size - 1; i >= 0; i--) {
		cout << a.data[i];
	}
}

BigNumber& dp(int n) {

	if (n < 0) { return zero; }

	if (cache[n].size != 0) {
		return cache[n];
	}

	cache[n] = sum(dp(n - 1), dp(n - 2));

	return cache[n];
}

BigNumber set(string in) {

	BigNumber result;

	for (int i = 0; i <= in.size() / result.slice; i++) {

		for (int j = 0; j < result.slice; j++) {
			result.data[i] = in[i + j] - '0';
		}
		result.size++;
	}

	return result;
}

int main(int argc, char** argv) {
	int n;
	//cin >> n;

	string input;

	cache[0].data[cache[0].size++] = 0;
	cache[1].data[cache[1].size++] = 1;
	cache[2].data[cache[2].size++] = 1;

	//show(dp(n));

	BigNumber a, b, result;
	
	cin >> input;
	a = set(input);

	cin >> input;
	b = set(input);

	cout << a.size << ", " << b.size << '\n';

	show(a);
	cout << " + ";
	show(b);

	cout << " = ";
	result = sum(a, b);
	show(result);

	return 0;
}