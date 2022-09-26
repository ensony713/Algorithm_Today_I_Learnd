#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	vector<int> op, n;
	int result = 0;
	string input, num;
	bool minus = false;

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '-' || input[i] == '+') {
			op.push_back(input[i]);

			n.push_back(stoi(num));
			num = "";
		}
		else {
			num += input[i];
		}
	}
	n.push_back(stoi(num));

	result = n[0];
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '-') {
			minus = true;
		}
		if (minus) {
			result -= n[i + 1];
		}
		else {
			result += n[i + 1];
		}
	}

	cout << result;

	return 0;
}