#include <iostream>
#include <vector>
#include <string>
using namespace std;

string input, st;
vector<char> stack;

bool match(int index) {
	if (stack.size() <= 0) {
		return false;
	}

	if (st[index] == ')' && stack[stack.size() - 1] == '(') {
		return true;
	}
	if (st[index] == ']' && stack[stack.size() - 1] == '[') {
		return true;
	}

	return false;
}

bool vps(int size) {
	char tmp;
	stack.clear();

	for (int i = 0; i < size; i++) {
		if (st[i] == '(' || st[i] == '[') {
			stack.push_back(st[i]);
		}
		else if (match(i)) {
			stack.pop_back();
		}
		else if (st[i] == ')' || st[i] == ']') {
			return false;
		}
	}

	if (stack.size()) {
		return false;
	}

	return true;
}

int main(int argc, char** argv) {

	while (true) {
		st = "";

		getline(cin, st);

		if (st == ".") {
			return 0;
		}

		if (vps(st.size())) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}

	return 0;
}