#include <iostream>
#include <limits>
#define MAX 100
using namespace std;

int main(int argc, char** argv) {
	
	int N, S, start = 0, end = 0, sum, mini = numeric_limits<int>::max();
	cin >> N >> S;
	int nums[MAX] = { 0 };

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	sum = nums[start];

	while (end <= N) {

		if (sum >= S) {
			mini = mini < end - start + 1 ? mini : end - start + 1;
		}

		if (sum <= S) {
			sum += nums[++end];
		}
		else {
			sum -= nums[start++];
		}
	}

	if (mini != numeric_limits<int>::max()) {
		cout << mini;
	}
	else {
		cout << 0;
	}

	return 0;
}