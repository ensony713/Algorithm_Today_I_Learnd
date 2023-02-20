#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;

class MaxHeap {
	int size = 0;
	long data[MAX] = { 0 };

public:
	void insert(long n) {

		data[++size] = n;

		for (int i = size; i > 1; i = i / 2) {
			
			if (data[i] > data[i / 2]) {
				swap(data[i], data[i / 2]);
			}
			else { break; }
		}
	}

	long remove() {

		if (size == 0) {
			return 0;
		}

		long output = data[1], tmp;
		int rightI, leftI, idx;
		data[1] = data[size--];

		for (int i = 1; i <= size / 2;) {

			idx = i;
			leftI = i * 2;
			rightI = i * 2 + 1;

			if (leftI <= size && rightI <= size) {
				idx = data[leftI] > data[rightI] ? leftI : rightI;
			}
			else if (leftI <= size) {
				idx = leftI;
			}
			else if (rightI <= size) {
				idx = rightI;
			}

			if (data[i] < data[idx]) {
				swap(data[i], data[idx]);
				i = idx;
			}
			else { break; }
		}

		return output;
	}

	void showAll() {

		cout << "show all!\n";
		for (int i = 1; i <= size; i++) {
			cout << data[i] << " ";
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
	MaxHeap pQ;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;

		if (x == 0) {
			cout << pQ.remove() << '\n';
		}
		else {
			pQ.insert(x);
		}
	}

	return 0;
}