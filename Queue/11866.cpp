#include <iostream>
#define MAX 1005
using namespace std;

class Queue {
	int front, end;
	int data[MAX] = { 0 };
	int set(int i) {
		i %= MAX;
		if (i < 0) i += MAX;
		return i;
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

	int pop() {
		if (front == end) return -1;

		int tmp = data[front];
		front = set(front + 1);
		return tmp;
	}

	int size() {
		if (front > end) return MAX + (end - front);
		else return end - front;
	}

	void print() {
		for (int i = 0; i < this->size(); i++) {
			cout << data[set(front + i)] << " ";
		}
		cout << '\n';
	}
};

Queue q;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, count = 0;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	
	cout << "<";

	while (q.size() > 0) {

		count++;

		if (count == k) {
			cout << q.pop();
			count = 0;

			if (q.size() != 0) cout << ", ";
			else cout << ">";
		}
		else {
			q.push(q.pop());
		}
	}
	
	return 0;
}