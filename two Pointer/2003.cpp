#include <iostream>
#define MAX 100
using namespace std;

int sum(int nums[], int start, int end) {
	
	int result = 0;
	for (int i = start; i <= end; i++) {
		result += nums[i];
	}

	return result;
}

int main(int argc, char** argv) {
	
	int N, M, start = 0, end = 0;
	int nums[MAX], r, result = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	while (end < N) {

		r = sum(nums, start, end);

		if (r == M) { result++; }

		if (start == end) {
			end++;
		}
		else if (r <= M) {
			end++;
		}
		else {
			start++;
		}
	}

	cout << result;

	return 0;
}