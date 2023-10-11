#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int MAX = 503;

int solution(vector<vector<int>>& triangle) {

	int answer = 0;
	int cash[MAX][MAX] = { 0 };

	cash[0][0] = triangle[0][0];

	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 0; j <= i; j++) {
			
			if (j == 0) {
				cash[i][j] = cash[i - 1][j] + triangle[i][j];
			}
			else {
				cash[i][j] 
					= cash[i - 1][j] > cash[i - 1][j - 1] ?
					cash[i - 1][j] + triangle[i][j] : 
					cash[i - 1][j - 1] + triangle[i][j];
			}

			if (i == triangle.size() - 1) {
				answer = answer < cash[i][j] ? cash[i][j] : answer;
			}
		}
	}

	return answer;
}

int main(int argc, char** argv) {

	int h, a;
	vector<vector<int>> triangle;
	cin >> h;

	for (int i = 0; i < h; i++) {

		vector<int> tmp;
		for (int j = 0; j <= i; j++) {
			cin >> a;
			tmp.push_back(a);
		}
		triangle.push_back(tmp);
	}

	cout << solution(triangle);

	return 0;
}