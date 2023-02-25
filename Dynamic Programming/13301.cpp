#include <iostream>
#define MAX 100
using namespace std;

typedef unsigned long long number;

number cache[MAX] = { 0 }; // 황금비율 저장해둔 배열

number dp(int i) {
	if (i <= 0) { return 0; }

	if (cache[i] != 0) {
		return cache[i];
	}

	cache[i] = dp(i - 1) + dp(i - 3) + dp(i - 4);

	return cache[i];
}

int main(int argc, char** argv) {
	int n;
	cin >> n;

	cache[1] = 1;
	cache[2] = 1;
	cache[3] = 2;

	dp(n);
	

	number area;
	
	if (n >= 3) {
		area = cache[n] * 3;
		area += cache[n - 1] * 2;
		area += cache[n - 2] * 2;
		area += cache[n - 3];
	}
	else if (n == 2){
		area = 6;
	}
	else {
		area = 4;
	}
	cout << area;

	return 0;
}