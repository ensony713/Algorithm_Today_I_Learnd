#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;

class MinQueue {
	int size = 0;
	long data[MAX] = { 0 };

public:

	void insert(long n) {
		
		data[++size] = n;

		for (int i = size; i > 1; i = i / 2) {
			if (data[i] < data[i / 2]) {
				swap(data[i], data[i / 2]);
			}
			else { break; }
		}
	}

	long remove() {
		if (size == 0) { return 0; }

		long mini = data[1];
		int idx = 1, l, r;
		data[1] = data[size--];

		for (int i = 1; i <= size;) {

			l = i * 2;
			r = i * 2 + 1;

			if (l <= size && r <= size) {
				idx = data[l] < data[r] ? l : r;
			}
			else if (l <= size) {
				idx = l;
			}
			else if (r <= size) {
				idx = r;
			}

			if (data[idx] < data[i]) {
				swap(data[idx], data[i]);
				i = idx;
			}
			else { break; }
		}

		return mini;
	}
	
	void showAll() {
		cout << "\nshow all!\n";
		for (int i = 1; i <= size; i++) {
			cout << "'" << data[i] << "' ";
		}
		cout << '\n';
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long x;
	MinQueue mq;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;

		if (x == 0) {
			cout << mq.remove() << '\n';
		}
		else {
			mq.insert(x);
		}
	}

	return 0;
}