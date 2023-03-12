#include <iostream>
#include <memory.h>
#define MAX 100
using namespace std;

typedef char node;

class Stack {
	int top;
	node data[MAX];

public:
	Stack() {
		top = 0;
		memset(data, 0, sizeof(data));
	}

	void push(node x) {
		data[top++] = x;
	}

	node pop() {
		return data[--top];
	}

	node get_top() {
		return data[top - 1];
	}

	void init() {
		top = 0;
		memset(data, 0, sizeof(data));
	}

	int size() {
		if (top == 0) { return 0; }
		return top;
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Stack st;
	string input;
	int result = 0;
	char front = 0;
	cin >> input;

	for (int i = 0; i < input.size(); i++) {

		if (input[i] == '(') {
			st.push(input[i]);
		}

		if (input[i] == ')') {
			st.pop();

			if (front == '(') {
				result += st.size();
			}
			else {
				result++;
			}
		}

		front = input[i];
	}

	cout << result;

	return 0;
}