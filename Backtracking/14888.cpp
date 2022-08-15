#include <iostream>
#include <vector>
using namespace std;

typedef int number;

vector<number> num;
vector<int> commend;
int result[11] = { 0 };
bool visited[10];
number mini = INT32_MAX, maxi = INT32_MIN, vsize = 0;

void dfs(int deep) {
	if (deep >= commend.size()) {
		mini = mini > result[deep] ? result[deep] : mini;
		maxi = maxi < result[deep] ? result[deep] : maxi;
	}

	for (int i = 0; i < vsize; i++) {
		if (!visited[i]) {
			visited[i] = true;

			switch (commend[i]) {
			case 0:
				result[deep + 1] = result[deep] + num[deep + 1];
				break;
			case 1:
				result[deep + 1] = result[deep] - num[deep + 1];
				break;
			case 2:
				result[deep + 1] = result[deep] * num[deep + 1];
				break;
			case 3:
				result[deep + 1] = result[deep] / num[deep + 1];
				break;
			}

			dfs(deep + 1);
			visited[i] = false;
		}
	}
}

int main(int argc, char* argv[]) {
	int n, input, plus, minus, multiple, divide;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> input;
		num.push_back(input);
	}

	cin >> plus >> minus >> multiple >> divide;

	for (int i = 0; i < plus; i++) {
		commend.push_back(0);
	}
	for (int i = 0; i < minus; i++) {
		commend.push_back(1);
	}
	for (int i = 0; i < multiple; i++) {
		commend.push_back(2);
	}
	for (int i = 0; i < divide; i++) {
		commend.push_back(3);
	}

	vsize = commend.size();
	result[0] = num[0];
	dfs(0);

	cout << maxi << '\n' << mini << '\n';

	return 0;
}