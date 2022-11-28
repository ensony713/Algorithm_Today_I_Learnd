#include <iostream>
#define MAX 105
using namespace std;

class Queue {
	int front, end;
	int data[MAX] = { 0 };
	int priority[MAX] = { 0 };

	int set(int i) {
		i += MAX;
		i = i % MAX;
		return i;
	}

public:
	bool isMax(int pri) {
		for (int i = front; i != end; i = set(i + 1)) {
			if (pri < priority[i]) {
				return false;
			}
		}
		return true;
	}

	void init() {
		front = 0;
		end = 0;
	}

	Queue() {
		front = 0;
		end = 0;
	}

	void push(int x, int m) {
		data[end] = x;
		priority[end] = m;
		end = set(end + 1);
	}

	int pop(int & pri) {
		pri = priority[front];
		int tmp = data[front];
		front = set(front + 1);
		return tmp;
	}

	int print() {
		int pri = 0;
		while (!isMax(front)) {
			push(pop(pri), pri);
		}

		return pop(pri);
	}

	int size() {
		if (front > end) return MAX + (end - front);
		return end - front;
	}

	bool empty() {
		if (front == end) { return true; }
		return false;
	}
};

Queue printer;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, doc, input, count = 0, out = -1, pri;
	bool ismax;
	cin >> t;

	while (t-- > 0) {
		cin >> n >> doc;
		count = 0;
		printer.init();

		for (int i = 0; i < n; i++) {
			cin >> input;
			printer.push(i, input);
		}

		while (!printer.empty()) {

			out = printer.pop(pri);
			ismax = printer.isMax(pri);

			if (ismax && doc == out) {
				break;
			}
			else if (ismax) {
				count++;
			}
			else {
				printer.push(out, pri);
			}
		}

		cout << count << '\n';
	}

	return 0;
}