#include <iostream>
#include <string>
#define MAX 10005
using namespace std;

class Deque {
private:
	int value[MAX] = { 0 };
	int head, tail, tmp;
	int set(int i) {
		i = i % MAX;
		if (i < 0)
			i += MAX;
		return i;
	}
public:
	Deque() {
		this->head = 0;
		this->tail = 0;
		this->tmp = 0;
	}

	int empty() {
		if (this->head == this->tail)
			return 1;
		else
			return 0;
	}
	int size() {
		if (this->empty())
			return 0;
		if (this->tail > this->head)
			return this->tail - this->head;
		else
			return MAX - (this->head - this->tail);
	}

	int front() {
		if (this->empty())
			return -1;
		return this->value[this->head];
	}
	int back() {
		if (this->empty())
			return -1;
		return this->value[this->set(this->tail - 1)];
	}

	void push_front(int x) {
		this->head = this->set(this->head - 1);
		this->value[this->head] = x;
	}
	void push_back(int x) {
		this->value[this->tail] = x;
		this->tail = this->set(this->tail + 1);
	}

	int pop_front() {
		if (this->empty())
			return -1;
		tmp = this->value[this->head];
		this->head = this->set(this->head + 1);
		return tmp;
	}
	int pop_back() {
		if (this->empty())
			return -1;
		this->tail = this->set(this->tail - 1);
		tmp = this->value[this->tail];
		return tmp;
	}
};

int N, num, tmp;
string command;
Deque deq;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (; N > 0; N--) {
		cin >> command;
		
		if (command == "push_back") {
			cin >> num;
			deq.push_back(num);
		}
		else if (command == "push_front") {
			cin >> num;
			deq.push_front(num);
		}
		else if (command == "pop_back")
			cout << deq.pop_back() << "\n";
		else if (command == "pop_front")
			cout << deq.pop_front() << "\n";
		else if (command == "size")
			cout << deq.size() << "\n";
		else if (command == "empty")
			cout << deq.empty() << "\n";
		else if (command == "front")
			cout << deq.front() << "\n";
		else if (command == "back")
			cout << deq.back() << "\n";
	}
	return 0;
}