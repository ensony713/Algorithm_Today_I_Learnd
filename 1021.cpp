#include <iostream>
#define MAX 55
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

	int search(int n) {
		int counter = 0;
		if (this->empty())
			return -1;
		for (int i = this->head; i != this->tail; i = this->set(i + 1)) {
			if (this->value[i] == n)
				return counter;
			counter++;
		}
	}
};

int N, M, num, term, result = 0;
Deque q;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		q.push_back(i);

	for (int i = 0; i < M; i++) {
		cin >> num;
		term = q.search(num);

		for (; q.front() != num;) {
			if (term < q.size() - term) {
				q.push_back(q.pop_front());
				result++;
			}
			else {
				q.push_front(q.pop_back());
				result++;
			}
		}
		q.pop_front();
	}
	cout << result << "\n";
	return 0;
}