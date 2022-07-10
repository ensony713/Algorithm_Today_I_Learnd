#include <iostream>
#define MAX 4001
#define SCOPE 100
using namespace std;

class Counting {
private:
	int size = 0; // 요소 개수
	int nlist[MAX] = { 0 }; // 음수부
	int plist[MAX] = { 0 }; // 양수부
	int sorted[SCOPE] = { 0 }; // 정렬된 배열
	int sum = 0;

public:
	void set(int n) {
		int tmp;
		size = n;

		for (int i = 0; i < n; i++) {
			cin >> tmp;

			if (tmp < 0) {
				nlist[tmp * -1]++;
			}
			else {
				plist[tmp]++;
			}

			sum += tmp;
		}
	}

	void sort() {
		int index = 0;
		for (int i = MAX - 1; i >= 0; i--) {
			for (int j = 0; j < nlist[i]; j++) {
				sorted[index++] = i * -1;
			}
		}

		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < plist[i]; j++) {
				sorted[index++] = i;
			}
		}
	}

	int middle() {
		return sorted[size / 2];
	}

	int average() {
		int tmp;
		if (sum < 0) {
			tmp = (double) sum / (double) size - 0.5;
		}
		else {
			tmp = (double) sum / (double) size + 0.5;
		}

		return tmp;
	}

	int maxCount() {
		int count = 0, num, overlap = 0;

		for (int i = MAX - 1; i >= 0; i--) {
			if (count == nlist[i] && overlap == 0) {
				overlap++;
				num = i * -1;
			}
			else if (count < nlist[i]) {
				count = nlist[i];
				overlap = 0;
				num = i * -1;
			}
		}

		for (int i = 0; i < MAX; i++) {
			if (count == plist[i] && overlap == 0) {
				overlap++;
				num = i;
			}
			else if (count < plist[i]) {
				count = plist[i];
				overlap = 0;
				num = i;
			}
		}

		return num;
	}

	int scope() {
		return sorted[size - 1] - sorted[0];
	}
};

int main() {
	ios_base::sync_with_stdio(NULL);
	cout.tie(NULL);
	cin.tie(NULL);

	Counting co;
	int n;
	cin >> n;
	co.set(n);

	co.sort();
	cout << co.average() << '\n';
	cout << co.middle() << '\n';
	cout << co.maxCount() << '\n';
	cout << co.scope() << '\n';

	return 0;
}