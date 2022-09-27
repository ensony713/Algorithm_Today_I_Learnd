#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
	vector<int> stack;

public:

	void push(int x) {
		stack.push_back(x);
	}

	int empty() {
		if (stack.empty()) return 1;
		return 0;
	}

	int pop() {
		if (stack.empty()) {
			return -1;
		}
		int x = stack[stack.size() - 1];
		stack.pop_back();
		return x;
	}

	int size() {
		return stack.size();
	}

	int top() {
		if (stack.empty()) {
			return -1;
		}
		return stack[stack.size() - 1];
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	string op;
	Stack st;

	cin >> n;
	for (int i = 0; i < n; i++) {

		cin >> op;
		if (!op.compare("push")) {
			cin >> x;
			st.push(x);
		}
		if (!op.compare("pop")) {
			cout << st.pop() << '\n';
		}
		if (!op.compare("size")) {
			cout << st.size() << '\n';
		}
		if (!op.compare("empty")) {
			cout << st.empty() << '\n';
		}
		if (!op.compare("top")) {
			cout << st.top() << '\n';
		}
	}

	return 0;
}