#include <iostream>
#include <string>
#define MAX 2000000
using namespace std;

int num[MAX] = { 0 };
int start, q_end, tmp;

int set(int index) {
	index = index % MAX;
	if (index < 0)
		index += MAX;
	return index;
}

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
			push(x);
		}
		else if (command == "pop")
			cout << pop() << "\n";
		else if (command == "size")
			cout << size() << "\n";
		else if (command == "empty")
			cout << empty() << "\n";
		else if (command == "front")
			cout << front() << "\n";
		else if (command == "back")
			cout << back() << "\n";
	}
	return 0;
}