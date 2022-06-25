#include <iostream>
#include <string>
#define MAX 100005
using namespace std;

class Deque {
private:
	int head, tail, tmp;
	int value[MAX] = { 0 };
	bool forward;
	int set(int index) {
		if (index < 0)
			index += MAX;
		index = index % MAX;
		return index;
	}

public:
	Deque() {
		this->head = 0;
		this->tail = 0;
		this->tmp = 0;
		this->forward = true;
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

	void show() {
		if (this->empty())
			return;
		for (int i = this->head; i != this->tail; i = this->set(i + 1))
			cout << this->value[i] << " ";
		cout << "\n";
	}

	void show_and_pop() {
		cout << "[";
		while (!this->empty()) {
			if (this->forward)
				cout << pop_front();
			else
				cout << pop_back();
			if (this->size() != 0)
				cout << ",";
		}
		cout << "]\n";
	}
	void switching() {
		if (this->forward)
			this->forward = false;
		else
			this->forward = true;
	}
	bool pop() {
		if (this->empty())
			return false;
		if (this->forward)
			pop_front();
		else
			pop_back();
		return true;
	}
	void reset() {
		this->head = 0;
		this->tail = 0;
		this->forward = true;
	}
};

int T, n, num[MAX], tmp, unit;
bool result = true;
string p, x;
Deque q;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	for (; T > 0; T--) {
		cin >> p >> n >> x;

		if (n != 0) {
			tmp = 0;
			unit = 1;
			for (int i = x.size() - 2; i >= 0; i--) {
				if (48 <= int(x[i]) && int(x[i]) <= 57) {
					tmp += unit * (x[i] - 48);
					unit *= 10;
				}
				else {
					q.push_front(tmp);
					tmp = 0;
					unit = 1;
				}
			}
		}
		
		for (auto a : p) {
			if (a == 'R')
				q.switching();
			else if (a == 'D')
				result = q.pop();
			
			if (!result)
				break;
		}
		if (result)
			q.show_and_pop();
		else
			cout << "error\n";
			
		q.reset();
		result = true;
	}
}