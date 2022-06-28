#include <iostream>
#include <vector>
#define ZERO 97
using namespace std;

int main() {
	int N = 0, result = 0;
	char tem;
	vector<string> words;
	string word;
	bool letter[26];

	cin >> N;
	result = N;

	for (int i = 0; i < N; i++) {
		cin >> word;
		words.push_back(word);
	}

	for (int j = 0; j < N; j++) {
		word = words[j];

		for (int i = 0; i < 26; i++) {
			letter[i] = false;
		}

		for (unsigned int i = 0; i < word.size(); i++) {
			tem = word[i];

			if (letter[tem - ZERO] && i != 0 && word[i - 1] != tem) {
				result--;
				break;
				
			}

			letter[tem - ZERO] = true;
		}
	}

	cout << result;
}