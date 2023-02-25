#include <iostream>
#define MAX 50
using namespace std;

typedef struct alpha{
	int a;
	int b;
};

alpha cache[MAX] = { 0 };

bool empty(int i) {
	if (cache[i].a == 0 && cache[i].b == 0) {
		return true;
	}
	return false;
}

alpha dp(int deep) {

	alpha tmp;
	tmp.a = 0;
	tmp.b = 0;

	if (deep < 0) {
		return tmp;
	}

	if (!empty(deep)) {
		return cache[deep];
	}

	tmp = dp(deep - 1);

	cache[deep].a = tmp.b;
	cache[deep].b = tmp.a + tmp.b;

	return cache[deep];
}

int main(int argc, char** argv) {
	int k;
	cin >> k;

	cache[0].a = 1;
	cache[0].b = 0;
	alpha result = dp(k);

	cout << result.a << " " << result.b << '\n';
	
	return 0;
}