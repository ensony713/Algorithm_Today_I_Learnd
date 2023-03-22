#include <iostream>
#include <vector>
#define MOD 1000000007
#define MAX 100
using namespace std;

typedef unsigned long long node;

class SegmentTree {
	int size;
	vector<node> data;

public:
	SegmentTree(int n) {
		size = n;
		int s = n * 3;
		data.resize(s, 0);
	}

	node push(node d[], int start, int end, int key) {

		if (end == start) {
			data[key] = d[start];
			return data[key];
		}

		node left = push(d, start, (start + end) / 2, key * 2),
			right = push(d, (start + end) / 2 + 1, end, key * 2 + 1);

		data[key] = (left * right) % MOD;
		return data[key];
	}

	// d도 data도 index 1부터 시작
	void init(node d[], int n) {
		push(d, 1, n, 1);
	}

	void change(node d[], int idx, node x) {

		int i = 1, start = 1, end = size, mid;
		while (start != end) {
			data[i] = 1;
			mid = (start + end) / 2;

			if (mid < idx) {
				start = mid + 1;
				i = i * 2 + 1;
			}
			else {
				end = mid;
				i = i * 2;
			}
		}

		data[i] = x;

		while (i > 1) {
			i = i / 2;
			data[i] = (data[i * 2] * data[i * 2 + 1]) % MOD;
		}
	}

	// start ~ end : 구하려는 구간의 시작 ~ 끝
	// left ~ right : data[key] 값이 의미하는 구간
	node prefixSum(int start, int end, int left, int right, int key) {

		if (left > end || right < start) {
			return 1;
		}

		if (start <= left && right <= end) {
			return data[key];
		}

		node lv = prefixSum(start, end, left, (left + right) / 2, key * 2),
			rv = prefixSum(start, end, (left + right) / 2 + 1, right, key * 2 + 1);

		return (lv * rv) % MOD;
	}

	void show() {
		for (auto& a : data) {
			 cout << a << " ";
		}
		cout << '\n';
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	node input[MAX] = { 0 };
	int n, m, k, a, b, c;
	cin >> n >> m >> k;
	SegmentTree sgt(n);

	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}

	sgt.init(input, n);

	while (m + k > 0) {
		cin >> a >> b >> c;
		
		if (a == 1) {
			sgt.change(input, b, c);
			input[b] = c;
			m--;
		}
		if (a == 2) {
			cout << sgt.prefixSum(b, c, 1, n, 1) << '\n';
			k--;
		}
	}

	return 0;
}