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

class Quick { // 퀵 정렬
private:
	int size = 0;
	int list[MAX] = { 0 };

public:
	void set(int n) {
		size = n;
		for (int i = 0; i < n; i++) {
			cin >> list[i];
		}
	}

	void insert(int i, int n) {
		list[i] = n;
	}

	void divide(int L, int R) {
		if (L < R) {
			int p = partition(L, R);
			divide(L, p);
			divide(p + 1, R);
		}
	}

	int partition(int L, int R) {
		int base = L,
			low = L + 1,
			high = R,
			tmp;

		while (low < high) {
			while (low <= R && list[low] < list[base]) { low++; }
			while (high >= L && list[high] > list[base]) { high++; }
			if (low < high) {
				tmp = list[low];
				list[low] = list[high];
				list[high] = tmp;
			}
		}

		tmp = list[high];
		list[high] = list[base];
		list[base] = tmp;

		return high;
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << list[i] << ' ';
		}
		cout << '\n';
	}
};

class Merge { // 병합 정렬
private:
	int size = 0;
	int sorted[MAX] = { 0 };
	int list[MAX] = { 0 };

public:
	void set(int n) {
		size = n;
		for (int i = 1; i <= n; i++) {
			cin >> list[i];
		}
	}

	void insert(int i, int n) {
		list[i] = n;
	}

	void sort(int L, int R) {
		if (L < R) {
			int mid = R / 2;
			sort(L, mid);
			sort(mid + 1, R);
			step_merge(L, mid + 1, R);
		}
	}

	void step_merge(int L, int M, int R) {

		int n = 0,
			l = L,
			r = M,
			index = L,
			start, end;
		
		while (l <= M && r <= R) {
			if (list[l] < list[r]) {
				sorted[index++] = list[l++];
			}
			else {
				sorted[index++] = list[r++];
			}
		}
		
		if (l != M) {
			start = l; end = M;
		}
		else if (r != R) {
			start = r; end = R;
		}

		for (int i = start; i <= end; i++) {
			sorted[i] = list[i];
		}
	}

	void print() {
		for (int i = 0; i < size; i++) {
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
	Quick q;
	Merge m;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> list[i];
		heap.insert(list[i]);
		//q.insert(i, list[i]);
		//m.insert(i, list[i]);
	}
	
	for (int i = 0; i < N; i++) {
		cout << heap.pop() << ' ';
	}
	cout << '\n';
	
	//q.divide(0, N - 1);
	//q.print();
	
	//m.sort(1, N);
	//m.print();
	
	return 0;
}