#include <iostream>
#define MAX 105
using namespace std;

typedef struct {
	int num;
	int index;
}element;

class Queue {
private:
	int start, end_, tmp;
	element value[MAX] = { 0 };
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

	void push(int i, int x) {
		this->value[this->end_].num = x;
		this->value[this->end_].index = i;
		this->end_ = this->set(this->end_ + 1);
		return;
	}

	int pop(int & i) { // i에 index, 가중치 return
		if (this->empty())
			return -1;

		this->tmp = value[this->start].num;
		i = value[this->start].index;
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
		return this->value[this->start].index;
	}

	int back() {
		if (this->empty())
			return -1;
		return this->value[this->end_ - 1].index;
	}

	void show() {
		for (int i = this->start; i < this->end_; i = this->set(i + 1))
			cout << "(" << this->value[i].index << ", " << this->value[i].num << ") ";
		cout << "\n";
	}

	int max() {
		int max_value = -1;
		if (this->empty())
			return -1;
		for (int i = this->start; i != this->end_; i = this->set(i + 1))
			max_value = max_value < this->value[i].num ? this->value[i].num : max_value;
		return max_value;
	}

	void reset() {
		this->start = 0;
		this->end_ = 0;
	}
};

int N, T, M, v, maximum = -1, result, num;
Queue q;

int main() {
	cin >> T;
	while (T > 0) {
		q.reset();
		result = 1;

		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> v;
			q.push(i, v);
		}
		
		while (!q.empty()) {
			maximum = q.max();
			num = q.pop(v);
			if (num == maximum && v == M) {
				break;
			}
			else if (num != maximum) {
				q.push(v, num);
			}
			else
				result++;
		}
		cout << result << "\n";
		T--;
	}
	return 0;
}