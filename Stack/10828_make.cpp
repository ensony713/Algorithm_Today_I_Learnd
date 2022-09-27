#include <iostream>
#define MAX 100
using namespace std;

class Stack {
private:
	int tp, data[MAX] = { 0 };

public:
	Stack() {
		tp = 0;
	}

	int empty() {
		if (tp == 0) { return 1; }
		return 0;
	}

	void push(int x) {
		data[tp++] = x;
	}

	int pop() {
		if (empty()) { return -1; }
		return data[--tp];
	}

	int size() {
		return tp;
	}

	int top() {
		if (empty()) { return -1; }
		return data[tp - 1];
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