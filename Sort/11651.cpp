#include <iostream>
#include <string>
#define MAX 100
using namespace std;

class Point {
public:
	int x, y;

	Point() {
		x = 0; y = 0;
	}

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	string toString() {
		return to_string(x) + " " + to_string(y);
	}

	bool operator < (Point& t) {
		if (this->y < t.y) {
			return true;
		}
		else if (this->y == t.y && this->x < t.x) {
			return true;
		}
		return false;
	}

	bool operator <= (Point& t) {
		if (this->y < t.y) {
			return true;
		}
		else if (this->y == t.y && this->x < t.x) {
			return true;
		}
		else if (this->x == t.x && this->y == t.y) {
			return true;
		}
		return false;
	}

	bool operator == (Point& t) {
		if (this->x == t.x && this->y == t.y) {
			return true;
		}
		return false;
	}
};

class Merge {
	Point list[MAX];
	Point sorted[MAX];
	int size;

public:
	Merge() {
		size = 0;
	}

	void set(int n) {
		Point t;
		size = n;

		for (int i = 0; i < size; i++) {
			cin >> t.x >> t.y;
			list[i] = t;
		}
	}

	void print(bool con) {
		if (con) {
			for (int i = 0; i < size; i++) {
				cout << sorted[i].toString() << '\n';
			}
		}
		else {
			for (int i = 0; i < size; i++) {
				cout << list[i].toString() << '\n';
			}
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
		int li = L;
		int ri = M;
		int index = L, start = 0, end = 0;

		while (li < M && ri <= R) {
			if (list[li] < list[ri]) {
				sorted[index++] = list[li++];
			}
			else {
				sorted[index++] = list[ri++];
			}
		}

		if (li < M) {
			for (int i = li; i < M; i++) {
				sorted[index++] = list[i];
			}
		}
		if (ri <= R) {
			for (int i = ri; i <= R; i++) {
				sorted[index++] = list[i];
			}
		}

		for (int i = L; i <= R; i++) {
			list[i] = sorted[i];
		}
	}
};

int main() {
	int N;
	Merge mg;

	cin >> N;

	mg.set(N);

	mg.sort(0, N - 1);

	mg.print(true);

	return 0;
}