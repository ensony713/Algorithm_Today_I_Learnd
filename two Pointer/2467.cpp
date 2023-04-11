#include <iostream>
#include <vector>
#include <stdlib.h>
#include <limits>
using namespace std;

int main(int argc, char** argv) {
	
	vector<long long> solution;
	long long input, mini = numeric_limits<long>::max();
	int n, i, j, first = 0, second = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		solution.push_back(input);
	}

	i = 0; j = solution.size() - 1;

	while (j != i) {

		if (abs(solution[i] + solution[j]) < mini) {
			mini = abs(solution[i] + solution[j]);
			first = i;
			second = j;
		}

		if (solution[i] + solution[j] < 0) {
			i++;
		}
		else {
			j--;
		}
	}

	cout << solution[first] << " " << solution[second];

	return 0;
}