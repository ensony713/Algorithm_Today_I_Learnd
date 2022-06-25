#include <iostream>
#define MAX 1005
using namespace std;

class Queue {
private:
	int start, end_, tmp;
	int value[MAX] = { 0 };
	int set(int index) {
		index = index % MAX;
		if (index < 0)
			index += MAX;
		return index;
	}
public:
	Queue() {
		this->start = 0;
		this->end_ = 0;
		this->tmp = 0;
	}

	int empty() {
		if (this->start == this->end_)
			return 1;
		else
			return 0;
	}

	void push(int x) {
		this->value[this->end_] = x;
		this->end_ = this->set(this->end_ + 1);
		return;
	}

	int pop() {
		if (this->empty())
			return -1;

		this->tmp = value[this->start];
		this->start = this->set(this->start + 1);
		return this->tmp;
	}

	int size() {
		if (this->end_ >= this->start)
			return this->end_ - this->start;
		else
			return MAX + this->end_ - this->start;
	}

	int front() {
		if (this->empty())
			return -1;
		return this->value[this->start];
	}

	int back() {
		if (this->empty())
			return -1;
		return this->value[this->end_ - 1];
	}

	void show() {
		for (int i = this->start; i < this->end_; i++)
			cout << this->value[i] << " ";
		cout << "\n";
	}
};

int N, K, counter = 1, index = 0, tmp;
int answer[MAX];
Queue q;

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		q.push(i);

	while (q.size() > 1) {
		if (counter == K) {
			counter = 1;
			answer[index++] = q.pop();
		}
		else {
			counter++;
			tmp = q.pop();
			q.push(tmp);
		}
	}

	for (; !q.empty(); index++)
		answer[index] = q.pop();

	cout << "<";
	for (int i = 0; i < N; i++) {
		if (i != N - 1)
			cout << answer[i] << ", ";
		else
			cout << answer[i] << ">";
	}
	return 0;
}