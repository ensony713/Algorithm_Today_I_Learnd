#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

int lenght[MAX][MAX] = { 0 };

int main(int argc, char** argv) {
	
	string word1, word2;
	int result = 0;
	vector<int> idx;

	cin >> word1 >> word2;

	for (int i = 0; i < word1.size(); i++) {
		for (int j = 0; j < word2.size(); j++) {

			if (word1[i] == word2[j]) {
				lenght[i + 1][j + 1] = lenght[i][j] + 1;
			}
			else {
				lenght[i + 1][j + 1] = lenght[i][j + 1] > lenght[i + 1][j] ? lenght[i][j + 1] : lenght[i + 1][j];
			}

			result = result < lenght[i + 1][j + 1] ? lenght[i + 1][j + 1] : result;
		}
	}

	for (int i = 1; i <= word1.size(); i++) {
		for (int j = 1; j <= word2.size(); j++) {
			cout << lenght[i][j] << " ";
		}
		cout << '\n';
	}

	int i = word1.size(), j = word2.size();
	while (lenght[i][j] != 0) {
		if (lenght[i - 1][j] == lenght[i][j]) {
			i = i - 1;
		}
		else if (lenght[i][j - 1] == lenght[i][j]) {
			j = j - 1;
		}
		else if (lenght[i - 1][j - 1] == lenght[i][j] - 1) {
			idx.insert(idx.begin(), i);
			i = i - 1;
			j = j - 1;
		}
	}

	cout << result << "\n";
	for (auto& i : idx) {
		cout << word1[i - 1];
	}

	return 0;
}