#include <iostream>
#include <memory.h>
#define MAX 100
using namespace std;

class IntStack {
	int top;
	int data[MAX];

public:
	IntStack() {
		top = 0;
		memset(data, 0, sizeof(data));
	}

	bool empty() {
		if (top == 0) { return true; }
		return false;
	}

	int get_top() {
		return data[top - 1];
	}

	int size() {
		return top;
	}

	void push(int x) {
		data[top++] = x;
	}

	void pop() {
		top--;
	}
};

bool is_possible(IntStack st[], int in) {

	for (int i = 0; i < 4; i++) {
		
		if (st[i].size() == 0) {
			st[i].push(in);
			return true;
		}
		else if (st[i].get_top() < in) {
			st[i].push(in);
			return true;
		}
	}

	return false;
}

int main(int argc, char** argv) {

	bool putIn = false;
	IntStack st[4];
	int input[MAX] = { 0 };
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];

		putIn = is_possible(st, input[i]);
		if (!putIn) { break; }
	}

	if (putIn) {
		cout << "YES\n";
	}
	else { cout << "NO\n"; }

	return 0;
}