//#include <iostream>
//#include <algorithm>
//#include <string>
//#define MAX 6000
//using namespace std;
//
//string cache[MAX] = { "" };
//
//string sum(string a, string b) {
//
//	string result = "";
//	int ssize = min(a.size(), b.size());
//	int lsize = max(a.size(), b.size());
//	int carry = 0, sum;
//	int an, bn;
//
//	for (int i = 0; i < ssize; i++) {
//
//		sum = a[i] - '0' + b[i] - '0' + carry;
//		carry = sum / 10;
//
//		result += to_string(sum % 10);
//	}
//
//	for (int i = ssize; i < lsize; i++) {
//
//		an = a[i] - '0' >= 0 ? a[i] - '0' : 0;
//		bn = b[i] - '0' >= 0 ? b[i] - '0' : 0;
//
//		sum = an + bn + carry;
//		carry = sum / 10;
//
//		result += to_string(sum % 10);
//	}
//
//	if (carry > 0) {
//		result += to_string(carry);
//	}
//
//	return result;
//}
//
//void show(string n) {
//
//	for (int i = n.size(); i >= 0; i--) {
//		cout << n[i];
//	}
//}
//
//string dp(int n) {
//	if (n < 3) {
//		return cache[n];
//	}
//
//	if (cache[n] != "") {
//		return cache[n];
//	}
//
//	cache[n] = sum(dp(n - 1), dp(n - 2));
//
//	return cache[n];
//}
//
//int main(int argc, char** argv) {
//	int n;
//	cin >> n;
//
//	cache[0] = "0";
//	cache[1] = "1";
//	cache[2] = "1";
//
//	show(dp(n));
//
//	return 0;
//}