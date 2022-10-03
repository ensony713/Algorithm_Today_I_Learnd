#include <iostream>
#include <vector>
using namespace std;

bool right_f = true;
int n, input[100000] = { 0 }, index = 0;
vector <int> stack;
vector <char> result;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	stack.push_back(0);
	for (int i = 1; i <= n; i++) {
		stack.push_back(i);
		result.push_back('+');
		for (auto j = stack[stack.size() - 1]; j == input[index]; j = stack[stack.size() - 1]) {
			if (j == 0) break;
			index++;
			stack.pop_back();
			result.push_back('-');
		}
		if (index > n) {
			right_f = false;
			break;
		}
	}
	if (stack.size() > 1) right_f = false;
	if (right_f) {
		for (auto i : result)
			cout << i << "\n";
	}
	else cout << "NO\n";

	return 0;
}