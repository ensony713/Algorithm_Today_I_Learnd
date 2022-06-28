#include <iostream>
#include <map>
using namespace std;

map<char, int> dial;

int main() {
	string input;
	int sec = 0;

	for (int i = 0; i < 15; i++) {
		dial[(char)(i + 65)] = i / 3 + 3;
	}

	dial['P'] = 8;
	dial['Q'] = 8;
	dial['R'] = 8;
	dial['S'] = 8;
	dial['T'] = 9;
	dial['U'] = 9;
	dial['V'] = 9;
	dial['W'] = 10;
	dial['X'] = 10;
	dial['Y'] = 10;
	dial['Z'] = 10;

	cin >> input;

	for (char c : input) {
		sec += dial[c];
	}

	cout << sec;

	return 0;
}