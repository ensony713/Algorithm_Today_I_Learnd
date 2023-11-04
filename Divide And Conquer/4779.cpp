#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 600000;
// '-' = false
// ' ' = true
void cantorian_set(bool result[], int start, int end) {

	if (end - start < 3) {
		return ;
	}

	int base = (end - start) / 3;
	cantorian_set(result, start, start + base);
	for (int i = start + base; i < start + base + base; i++) {
		result[i] = true;
	}
	cantorian_set(result, start + base + base, end);
}

void show(bool* result, int n) {

	int limite = pow(3, n);
	for (int i = 0; i < limite; i++) {
		if (result[i]) {
			cout << " ";
		}
		else {
			cout << "-";
		}
	}
	cout << '\n';
}

int main(int argc, char** argv) {

	int n;
	
	while (1) {

		cin >> n;
		if (cin.eof()) break;

		bool result[MAX] = { 0 };

		cantorian_set(result, 0, pow(3, n));

		show(result, n);
	}

	return 0;
}