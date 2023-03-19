#include <iostream>
#include <list>
#include <iterator>
using namespace std;

typedef char node;

class Stack {
	list<node>::iterator cursor;
	list<node> data;

public:
	Stack() {
		cursor = data.begin();
	}

	void push(node x) {
		data.insert(cursor, x);
	}

	void pop() {
		if (cursor == data.begin()) { return; }
		cursor--;
		cursor = data.erase(cursor);
		// erase를 사용할 경우, Where로 주어진 iterator는 사용할 수 없는 상태가 됨
		// 따라서 erase 메소드의 반환인 제거된 요소 뒤 중 가장 첫번째 요소를 다시 iterator에 넣어줘야 함
	}

	void right_shift() {
		if (cursor == data.end()) { return; }
		cursor++;
	}

	void left_shift() {
		if (cursor == data.begin()) { return; }
		cursor--;
	}

	void init() {
		data.clear();
		cursor = data.begin();
	}

	void show() {
		for (auto& d : data) {
			cout << d;
		}
		cout << '\n';
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	string input;
	Stack keylogger;
	cin >> t;

	for (; t > 0; t--) {

		cin >> input;
		for (int i = 0; i < input.size(); i++) {

			if (input[i] == '<') {
				keylogger.left_shift();
			}
			else if (input[i] == '>') {
				keylogger.right_shift();
			}
			else if (input[i] == '-') {
				keylogger.pop();
			}
			else {
				keylogger.push(input[i]);
			}
		}

		keylogger.show();
		keylogger.init();
	}

	return 0;
}