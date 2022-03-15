#include <iostream>
#define MAX 500005
using namespace std;

class Queue {
private:
	int num[MAX] = { 0 };
	int start, q_end, tmp;
	int set(int index) {
		index = index % MAX;
		if (index < 0)
			index += MAX;
		return index;
	}

public:
	int empty() {
		if (start == q_end)
			return 1;
		else
			return 0;
	}

	void push(int a) {
		num[q_end] = a;
		q_end = set(q_end + 1);
		return;
	}

	int pop() {
		if (empty())
			return -1;

		tmp = num[start];
		start = set(start + 1);
		return tmp;
	}

	int size() {
		if (q_end >= start)
			return q_end - start;
		else
			return MAX + q_end - start;
	}

	int front() {
		if (empty())
			return -1;
		return num[start];
	}

	int back() {
		if (empty())
			return -1;
		return  num[q_end - 1];
	}
};

int N, tmp;
Queue que;

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++)
		que.push(i);

	while (que.size() > 1) {
		que.pop();
		tmp = que.front();
		que.pop();
		que.push(tmp);
	}
	cout << que.front() << "\n";
	return 0;
}