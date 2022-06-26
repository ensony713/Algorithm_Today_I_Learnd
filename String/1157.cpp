#include <iostream>
#include <string>
using namespace std;

string input;
int alphabet[26] = { 0 }, _ = 0, maximum = -1, word = 0;
bool same = false;

void uppercase(string & in) {
	for (int i = 0; i < in.size(); i++) {
		if ((int)in[i] > 91)
			in[i] = (int)in[i] - 32;
	}
}

int main() {
	cin >> input;
	uppercase(input);
	for (int i = 0; i < input.size(); i++) {
		_ = (int)input[i] - 65;
		alphabet[_]++;
	}
	for (int i = 0; i < 26; i++) {
		if (maximum == alphabet[i]) {
			maximum = alphabet[i];
			same = true;
		}
		if (maximum < alphabet[i]) {
			maximum = alphabet[i];
			word = i + 65;
			same = false;
		}
	}
	if (same)
		cout << "?\n";
	else
		cout << (char)word << "\n";
	return 0;
}