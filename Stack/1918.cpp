#include <iostream>
#include <memory.h>
#define MAX 100
using namespace std;

/*
	1. +, - out bracket
	2. *, / out bracket
	3. +, - in bracket
	4. *, / in bracket
	5. +, - in two bracket
	6. *, / in two bracket
	...
*/

class node{
public:
	char data;
	int pri;
	
	void set(char o, int b) {
		data = o;
		
		if (o == '-' || o == '+') {
			pri = 1 + b * 2;
		}
		if (o == '*' || o == '/') {
			pri = 2 + b * 2;
		}
	}
	
	bool operator> (node & x) {
		if (this->pri > x.pri) {
			return true;
		}
		return false;
	}
	
	bool operator== (node& x) {
		if (this->pri == x.pri) {
			return true;
		}
		return false;
	}
};

class Stack{
	
	int top;
	node data[MAX];
	
public:
	
	Stack() {
		top = 0;
		memset(data, 0, sizeof(data));
	}
	
	bool empty() {
		if (top == 0) { return true; }
		return false;
	}

	void push(node x) {
		data[top++] = x;
	}	
	
	void pop() {
		if (empty()) { return ; }
		top--;
	}
	
	int size() {
		return top;
	}
	
	void priority_push(node& x) {
		
		while(true) {
			
			if (empty() || x > data[top-1]) {
				push(x);
				return;
			}
			
			cout << data[top-1].data;
			pop();
		}
	}
	
	void show() {
		for (int i = top - 1; i >= 0; i--) {
			cout << data[i].data;
		}
		cout << '\n';
	}
};

int main(int argc, char** argv) {
	
	string input;
	Stack oper;
	int pri = 0;
	node tmp;
	
	cin >> input;
	
	for (int i = 0; i < input.size(); i++) {
		
		if ('A' <= input[i] && input[i] <= 'Z') {
			cout << input[i];
		}
		else if (input[i] == '*' || input[i] == '/' || input[i] == '+' || input[i] == '-') {
			tmp.set(input[i], pri);
			oper.priority_push(tmp);
		}
		else if (input[i] == '(') {
			pri++;
		}
		else if (input[i] == ')') {
			pri--;
		}
	}
	
	oper.show();
	
	return 0;
}
