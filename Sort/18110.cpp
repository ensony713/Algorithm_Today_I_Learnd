#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 3 * 100000;

// 구현한 거 44ms, algorithm 32ms 인데 이정돈 무의미한 차이 같은데?
// 객체를 만드는 시간 때문엔가.

class Sort {

	vector<int> sorted;

	// 병합
	void merge(vector<int>& num, int start, int mid, int end) {

		// 병합
		int right = start, left = mid + 1, idx = start;
		while (right < mid + 1 && left <= end) {
			sorted[idx++] = num[right] < num[left] ? num[right++] : num[left++];
		}

		for (int i = right; i < mid + 1; i++) {
			sorted[idx++] = num[i];
		}
		for (int i = left; i <= end; i++) {
			sorted[idx++] = num[i];
		}

		for (int i = start; i <= end; i++) {
			num[i] = sorted[i];
		}
	}

public:

	Sort(int n) {
		sorted.resize(n, 0);
	}
	
	void merge_sort(vector<int>& num, int start, int end) {

		if (start < end) {
			int mid = (start + end) / 2;
			merge_sort(num, start, mid);
			merge_sort(num, mid + 1, end);
			merge(num, start, mid, end);
		}
	}
};

// O(n)의 평균구하기
int get_mean(vector<int>& number) {

	// 300,000 * 30 = 9,000,000 int 범위 안
	int result = 0;

	for (int i : number) {
		result += i;
	}

	// 나누는 수 / 2 > 나머지 -> 버림
	if (result % number.size() == 0 || (number.size() / 2 > result % number.size())) {
		return result / number.size();
	}

	result /= number.size();
	return ++result;
}

// 극단값 절삭
// number를 n% 비율로 극단값 절삭
void cutting(vector<int>& number, int n) {

	// 절삭할 인원 수
	int cnt = number.size() * n / 200;

	// 나누는 수 / 2 <= 나머지 -> 올림
	// 나누는 수 / 2 > 나머지 -> 버림
	if (100 <= (number.size() * n) % 200) {
		cnt++;
	}

	number.erase(number.begin(), number.begin() + cnt);
	number.erase(number.end() - cnt, number.end());
}

int regular(vector<int>& number) {
	
	// 정렬
	sort(number.begin(), number.end());

	// 절삭
	cutting(number, 30);

	return get_mean(number);
}

int making(vector<int>& number) {

	Sort sort(number.size());

	//정렬
	sort.merge_sort(number, 0, number.size() - 1);

	// 절삭
	cutting(number, 30);

	return get_mean(number);
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, input;
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	vector<int> number(n);

	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}

	cout << making(number);
	//cout << regular(number);

	return 0;
}