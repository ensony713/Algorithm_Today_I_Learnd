//#include <iostream>
//using namespace std;
//
//int main() {
//	string word, tem, pls;
//	int result = 0;
//
//	cin >> word;
//	result = word.size();
//
//	for (int i = 0; i < word.size(); i++) {
//		tem = word[i];
//
//		if (tem == "-" || tem == "=") {
//			result--;
//		}
//
//		if (i != 0 && tem == "j") {
//			if (word[i - 1] == 'l' || word[i - 1] == 'n') {
//				result--;
//			}
//		}
//
//		if (tem == "d" && i < (word.size() - 2)) {
//			if (word[i + 1] == 'z' && word[i + 2] == '=') {
//				result--;
//			}
//		}
//	}
//	cout << result;
//}