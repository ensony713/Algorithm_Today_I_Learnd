#include <iostream>
#include <vector>
using namespace std;

string ps;
vector<char> stack;

bool VPS(int size) {
	stack.clear();
	for (int i = 0; i < size; i++) {
		if (ps[i] == '(') {
			stack.push_back(ps[i]);
		}
		else if (stack.size() <= 0) { // 여는 괄호 개수 부족
			return false;
		}
		else {
			stack.pop_back();
		}
	}

	if (stack.size() > 0) { // 닫는 괄호 개수 부족
		return false;
	}
	return true;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> ps;
		if (VPS(ps.size())) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}