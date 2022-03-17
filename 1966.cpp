#include <iostream>
#define MAX 110
using namespace std;

typedef struct {
	int value;
	int index;
}element;

typedef struct {
	element heap[MAX];
	int size;
} type_heap;

type_heap q;
int T, N, M, tmp1, tmp2;

void swap(int a, int b) {
	tmp1 = q.heap[a].value;
	tmp2 = q.heap[a].index;
	q.heap[a].value = q.heap[b].value;
	q.heap[a].index = q.heap[b].index;
	q.heap[b].value = tmp1;
	q.heap[b].index = tmp2;
}

void insert(int index, int x) {
	q.heap[++q.size].index = index;
	q.heap[q.size].value = x;
	int i = q.size;
	while ((i > 1) && (q.heap[i / 2].value < q.heap[i].value)) {
		swap(i / 2, i);
		i = i / 2;
	}
}

element delete_heap() {
	int child = 2, parent = 1;
	element item = q.heap[1];
	q.heap[1].value = q.heap[q.size].value;
	q.heap[1].index = q.heap[q.size--].index;
	while (child <= q.size) {
		if ((q.heap[child + 1].value < q.heap[child].value) && (child + 1 <= q.size))
			child++;
		if (q.heap[child].value > q.heap[parent].value) {
			swap(child, parent);
			parent = child;
			child = parent * 2;
		}
		else break;
	}
	return item;
}

int main() {
	int temp, result = 1;
	element tmp;
	cin >> T;
	//T = 1;
	for (int i = 0; i < T; i++) {
		q.size = 0;

		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			insert(i, temp);
		}

		while (1) {
			tmp = delete_heap();
			cout << "pop form heap " << tmp.index << ", " << tmp.value << "\n";
			if (tmp.index == M) break;
			result++;
		}
		cout << result << "\n";
	}
	return 0;
}