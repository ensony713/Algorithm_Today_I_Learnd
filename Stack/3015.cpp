#include <iostream>
#include <stack>
#define MAX 1000
using namespace std;

typedef struct node{
	unsigned long value;
	int count;
};

class Stack {
	int ptr = 0;
	node data[MAX] = { 0 };

public:

	bool empty() {
		if (ptr == 0) { return true; }
		return false;
	}

	void push(node x) {
		data[ptr++] = x;
	}

	void pop() {
		if (empty()) { return; }
		ptr--;
	}

	node& top() {
		return data[ptr - 1];
	}

	int size() {
		return ptr;
	}

	void show() {
		cout << ">> ";
		for (int i = ptr - 1; i >= 0; i--) {
			cout << data[i].value << "," << data[i].count << " ";
		}
		cout << '\n';
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	stack<node> st;
	unsigned long long n, result = 0;
	unsigned long input;
	node tmp;

	cin >> n >> input;
	tmp.value = input;
	tmp.count = 0;
	st.push(tmp);

	for (int i = 1; i < n; i++) {
		cin >> input;

		while (!st.empty() && st.top().value < input) {
			result += (unsigned long long) st.top().count + 1;
			st.pop();
		}

		if (st.empty()) {
			tmp.value = input;
			tmp.count = 0;
			st.push(tmp);
		}
		else if (st.top().value > input) {
			result++;
			tmp.value = input;
			tmp.count = 0;
			st.push(tmp);
		}
		else if (st.top().value == input) {
			result += (unsigned long long) ++st.top().count;
			if (st.size() > 1) {
				result++;
			}
		}
	}

	cout << result;

	return 0;
}