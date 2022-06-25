#include <string>
#define MAX 2000000
using namespace std;

class Queue {
private:
	int num[MAX] = { 0 };
	int start, end, tmp;

	int set(int index) {
		index = index % MAX;
		if (index < 0)
			index += MAX;
		return index;
	}

public:
	Queue() {
		this->start = 0;
		this->end = 0;
		this->tmp = 0;
	}

	int empty() {
		if (this->start == this->end)
			return 1;
		else
			return 0;
	}

	void push(int x) {
		this->num[this->end] = x;
		this->end = this->set(this->end + 1);
		return;
	}

	int pop() {
		if (this->empty())
			return -1;
		
		this->tmp = num[this->start];
		this->start = this->set(this->start + 1);
		return this->tmp;
	}

	int size() {
		if (this->end >= this->start)
			return this->end - this->start;
		else
			return MAX + this->end - this->start;
	}

	int front() {
		if (this->empty())
			return -1;
		return this->num[this->start];
	}

	int back() {
		if (this->empty())
			return -1;
		return this->num[this->end - 1];
	}

};

Queue q;
string command;
int N = 0, x = 0;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> command;

		if (command == "push") {
			cin >> x;
			q.push(x);
		}
		else if (command == "pop")
			cout << q.pop() << "\n";
		else if (command == "size")
			cout << q.size() << "\n";
		else if (command == "empty")
			cout << q.empty() << "\n";
		else if (command == "front")
			cout << q.front() << "\n";
		else if (command == "back")
			cout << q.back() << "\n";
	}
	return 0;
}
		return 0;
}
