#include <iostream>
#include <string>
#define MAX 100
using namespace std;

class Merge {
private:
	string list[MAX];
	string sorted[MAX];
	int size;

public:
	Merge() {
		size = 0;
	}

	void set(int n) {
		size = n;
		
		for (int i = 0; i < n; i++) {
			cin >> list[i];
		}
	}

	void sort(int L, int R) {
		if (L < R) {
			int mid = ((R - L) / 2) + L;
			sort(L, mid);
			sort(mid + 1, R);
			merge(L, mid + 1, R);
		}
	}

	void merge(int L, int M, int R) {
		int li = L, ri = M;
		int index = L;

		while (li < M && ri <= R) {
			
			if (list[li].length() > list[ri].length()) {
				sorted[index++] = list[ri++];
			}
			else if (list[li].length() == list[ri].length() && list[li] > list[ri]) {
				sorted[index++] = list[ri++];
			}
			else {
				sorted[index++] = list[li++];
			}
		}

		for (int i = li; i < M; i++) {
			sorted[index++] = list[i];
		}
		for (int i = ri; i <= R; i++) {
			sorted[index++] = list[i];
		}

		for (int i = L; i <= R; i++) {
			list[i] = sorted[i];
		}
	}

	void print(bool con) {
		if (con) {
			for (int i = 0; i < size; i++) {
				if (sorted[i].compare(sorted[i + 1]) != 0) {
					cout << sorted[i] << '\n';
				}
			}
		}
		else {
			for (int i = 0; i < size; i++) {
				if (list[i].compare(list[i + 1]) != 0) {
					cout << list[i] << '\n';
				}
			}
		}
	}
};

int main() {
	int N;
	cin >> N;

	Merge mg;
	
	mg.set(N);
	mg.print(false);

	mg.sort(0, N - 1);
	mg.print(false);
	
	return 0;
}