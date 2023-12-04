#include <iostream>
#include <string>
using namespace std;

const int MAX = 500003;

// index 0번을 쓰면 안돼서 string으론 안되네..
// idx부터 k개의 문자열 뒤집기
void reverse(int idx, int k, int n, char str[]) {

	int half = idx + (k - 1) / 2;
	int term = k - 1;

	// 홀수개면 중앙 idx를 바꿀 필요가 없으니까 half 감소
	if ((k % 2) == 1) {
		half--;
	}

	for (int i = idx; i <= half; i++) {
		//cout << i << " <-> " << i + term << '\n';

		char tmp = str[i];
		str[i] = str[i + term];
		str[i + term] = tmp;
		term -= 2;
	}
}

// s부터 e까지 출력
void show(int s, int e, char str[]) {

	for (int i = s; i <= e; i++) {
		cout << str[i];
	}
	cout << '\n';
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	char str[MAX] = { 0 };

	cin >> n >> k;
	
	// 문자열 입력
	for (int i = 1; i <= n; i++) {
		cin >> str[i];
	}

	// n == k면 그냥 뒤집어서 출력
	if (n == k) {
		reverse(1, k, n, str);
		show(1, n, str);
		return 0;
	}

	// k부터 끝까지
	for (int i = k; i <= n; i++) {
		cout << str[i];
	}

	// 앞에서 (k - 1)개를, n과 k의 홀짝여부 일치 = 뒤집기 / 불일치 = 유지
	// 당연함 같으면 뒤집기가 홀수번 일어나고 다르면 짝수번 일어나니까
	if ((n % 2) == (k % 2)) {
		reverse(1, k - 1, n, str);
	}
	show(1, k - 1, str);

	return 0;
}