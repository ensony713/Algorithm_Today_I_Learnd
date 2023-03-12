#include <iostream>
#include <iterator>
#include <list>
#define MAX 100
#define NOPE '-'
using namespace std;

class Note {
	list<char>::iterator cursor;
	list<char> node;

public:
	Note() {
		cursor = node.begin();
	}

	void push(char x) {
		node.push_back(x);
	}

	void init() {
		node.clear();
		cursor = node.begin();
	}

	void P(char x) {
		node.insert(cursor, x);
	}

	void L() {
		if (cursor == node.begin()) { return; }
		cursor--;
	}

	void D() {
		if (cursor == node.end()) { return; }
		cursor++;
	}

	void B() {
		if (cursor == node.begin()) { return; }
		cursor = node.erase(--cursor);
	}

	void show() {
		for (auto& n : node) {
			cout << n;
		}
		cout << '\n';
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	string input, commend;
	char x;
	Note note;

	cin >> input >> n;
	
	note.init();
	for (int i = 0; i < input.size(); i++) {
		note.push(input[i]);
	}

	for (int i = 0; i < n; i++) {
		cin >> commend;
		
		if (commend == "P") {
			cin >> x;
			note.P(x);
		}
		if (commend == "L") {
			note.L();
		}
		if (commend == "D") {
			note.D();
		}
		if (commend == "B") {
			note.B();
		}
	}

	note.show();

	return 0;
}