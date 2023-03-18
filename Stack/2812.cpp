#include <iostream>
#include <memory.h>
#define MAX 100
using namespace std;

typedef int node;

class Stack {
	int ptr;
	node data[MAX];

public:
	Stack() {
		ptr = 0;
		memset(data, 0, sizeof(data));
	}

	bool empty() {
		if (ptr == 0) { return true; }
		return false;
	}

	node top() {
		if (empty()) { return -1; }
		return data[ptr - 1];
	}

	void pop() {
		if (empty()) { return; }
		ptr--;
	}

	void push(node x) {
		data[ptr++] = x;
	}

	int size() {
		return ptr;
	}

	void show() {
		for (int i = 0; i < ptr; i++) {
			cout << data[i];
		}
		cout << '\n';
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	string input;
	Stack st;

	cin >> n >> k;
	cin >> input;

	for (int i = 0; i < n; i++) {

		while (!st.empty() && k > 0 && st.top() < (input[i] - '0')) {
			st.pop();
			k--;
		}

		st.push(input[i] - '0');
	}

	while (k > 0) {
		st.pop();
		k--;
	}

	st.show();

	return 0;
}