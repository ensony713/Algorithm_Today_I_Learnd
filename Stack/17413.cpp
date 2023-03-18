#include <iostream>
#include <memory.h>
#include <string>
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
		// 공백 문자를 항상 top에 존재하게 하기 위해 넣을 때 자리를 바꿔줌
		if (data[top - 1] == ' ') {
			data[top - 1] = x;
			data[top++] = ' ';
		}
		else {
			data[top++] = x;
		}
	}

	void pop() {
		if (top == 0) { return; }
		top--;
	}

	int size() {
		return top;
	}

	void init() {
		top = 0;
	}

	void pop_all() {
		for (int i = top - 1; i >= 0; i--) {
			cout << data[i];
		}
		top = 0;
	}

	void show() {
		for (int i = 0; i < top; i++) {
			cout << data[i] << ' ';
		}
		cout << "end" << '\n';
	}
};

int main(int argc, char** argv) {

	Stack st;
	string input;
	bool tag = false;

	getline(cin, input, '\n');
	
	for (int i = 0; i < input.size(); i++) {
		
		if (input[i] == '<') {
			st.pop_all();
			tag = true;
		}
		
		if (input[i] == ' ') {
			st.pop_all();
		}

		if (!tag) {
			st.push(input[i]);
		}
		else {
			cout << input[i];
		}

		if (input[i] == '>') {
			tag = false;
		}
	}

	st.pop_all();

	return 0;
}