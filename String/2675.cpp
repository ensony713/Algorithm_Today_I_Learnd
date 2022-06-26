#include <iostream>
#include <string>
using namespace std;

int T, R;
string input, output;

string roop_word(string in, int n) {
	string temp, result;
	for (int i = 0; i < in.size(); i++) {
		temp = in[i];
		for (int _ = 1; _ < n; _++)
			temp = temp + in[i];
		result = result + temp;
	}
	return result;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> R >> input;
		output = roop_word(input, R);
		cout << output << "\n";
	}
	return 0;
}