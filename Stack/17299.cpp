#include <iostream>
#include <limits.h>
#define MAX 100
using namespace std;

typedef struct values {
	int count, data;
};

class Stack {
	int size = 0;
	values data[MAX] = { 0 };

public:

	bool empty() {
		if (size == 0) { return true; }
		return false;
	}

	void push(int d, int c) {
		data[size].data = d;
		data[size++].count = c;
	}

	int top_c() {
		if (empty()) { return INT_MAX; }
		return data[size - 1].count;
	}

	int top_data() {
		if (empty()) { return INT_MAX; }
		return data[size - 1].data;
	}

	void pop() {
		
		if (empty()) {
			return;
		}

		size--;
	}
};

int input[MAX] = { 0 }, counter[MAX] = { 0 }, output[MAX] = { 0 };
Stack stack;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> input[i];
		counter[input[i]]++;
	}

	for (int i = n; i > 0; i--) {
		
		while (stack.top_c() <= counter[input[i]]) {
			stack.pop();
		}

		output[i] = stack.top_c() == INT_MAX ? -1 : stack.top_data();
		stack.push(input[i], counter[input[i]]);
	}

	for (int i = 1; i <= n; i++) {
		cout << output[i] << ' ';
	}

	return 0;
}