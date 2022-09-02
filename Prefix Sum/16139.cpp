#include <iostream>
using namespace std;

string S;
int q, l, r;
char a;

int alphabet[26] = { 0 };
int sum[26][200003] = { 0 };

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> S >> q;

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j <= S.size(); j++) {
			sum[i][j + 1] = sum[i][j];
			if ((S[j] - 97) == i) {
				sum[i][j + 1]++;
			}
		}

	}

	for (int i = 0; i < q; i++) {
		cin >> a >> l >> r;

		cout << sum[a - 97][r + 1] - sum[a - 97][l] << '\n';
	}
	return 0;
}