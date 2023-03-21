#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

typedef long long number;

class SegmentTree {
	int size;
	number data[MAX] = { 0 };

public:
	SegmentTree() {
		size = 0;
	}

	// d와 data는 1부터 값이 있어야 됨
	number child(number d[], int start, int end, int key) {

		if (end == start) {
			data[key] = d[start];
			return data[key];
		}

		number left = child(d, start, (start + end) / 2, key * 2),
			right = child(d, (start + end) / 2 + 1, end, key * 2 + 1);

		data[key] = left + right;
		return data[key];
	}

	void set(int size, number* d) {
		child(d, 1, size, 1);
		this->size = size;
	}

	void change(number d[], int num, number x) {

		int idx = 1, start = 1, end = size, mid = 0;
		while (end != start) {
			data[idx] -= d[num];
			mid = (start + end) / 2;

			if (num > mid) {
				start = mid + 1;
				idx = idx * 2 + 1;
			}
			else {
				end = mid;
				idx = idx * 2;
			}
		}

		data[idx] = x;
		
		while (idx > 0) {
			idx = idx / 2;
			data[idx] += x;
		}
	}

	// left ~ right : 합을 구해야 하는 구간
	// start ~ end : 현재 탐색하고 있는 노드가 담당하고 있는 구간
	// key : 현재 노드 index
	number prefixSum(int left, int right, int start, int end, int key) {

		if (right < start || end < left) {
			return 0;
		}
		if (left <= start && end <= right) {
			return data[key];
		}

		number result = prefixSum(left, right, start, (start + end) / 2, key * 2)
			+ prefixSum(left, right, (start + end) / 2 + 1, end, key * 2 + 1);

		return result;
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	SegmentTree segt;
	int n, m, k, sign, x;
	number input[MAX] = { 0 }, y;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}
	segt.set(n, input);

	while (m + k > 0) {
		cin >> sign >> x >> y;

		if (sign == 1) {
		// exchange
			segt.change(input, x, y);
			input[x] = y;
			m--;
		}
		else {
		// get prefix sum
			cout << segt.prefixSum(x, y, 1, n, 1) << '\n';
			k--;
		}
	}

	return 0;
}