#include <iostream>
#define MAX 100
using namespace std;

class Queue {
	int front, end;
	int data[MAX] = { 0 };

	int set(int index) {
		index += MAX;
		if (index >= MAX) {
			index %= MAX;
		}
		return index;
	}

public:
	Queue() {
		front = 0;
		end = 0;
	}

	void push(int x) {
		data[end] = x;
		end = set(end + 1);
	}

	void pop() {
		front = set(front + 1);
	}

	void show() {
		if (this->size() == 0) {
			cout << "empty\n";
			return;
		}

		for (int i = front; i != end; i = set(i + 1)) {
			cout << data[i] << " ";
		}
		cout << '\n';
	}

	int size() {
		if (front > end) return MAX + (end - front);
		return end - front;
	}
};

Queue q;
int n, input;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	while (true) {
		cin >> input;

		if (input == 0) {
			q.pop();
		}
		else if (input == -1) {
			q.show();
			break;
		}
		else if (q.size() < n) {
			q.push(input);
		}
	}

	return 0;
}