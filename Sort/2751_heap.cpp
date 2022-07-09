#include <iostream>
#define MAX 102
using namespace std;

class MiniHeap { // 힙 정렬
private:
	int size = 0; // 요소 개수
	int list[MAX] = { 0 }; // 1부터 사용

public:
	void insert(int n) {
		int index = ++size;

		while ((index != 1) && (n < list[index / 2])) {
			list[index] = list[index / 2];
			index /= 2;
		}
		list[index] = n;
	}

	int pop() {

		int result = list[1], parent, child, tmp, r;
		parent = 1;
		child = 2;
		tmp = size--;

		while (child <= size) {
			r = child + 1;
			if (r <= size && list[r] < list[child]) child = r;

			if (list[child] > list[tmp]) break;
			list[parent] = list[child];
			parent = child;
			child *= 2;
		}

		list[parent] = list[tmp];

		return result;
	}

	void print() {
		for (int i = 1; i <= size; i++) {
			cout << list[i] << ' ';
		}
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int list[MAX] = { 0 };
	MiniHeap heap;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> list[i];
		heap.insert(list[i]);
	}
	
	for (int i = 0; i < N; i++) {
		cout << heap.pop() << ' ';
	}
	cout << '\n';
	
	return 0;
}