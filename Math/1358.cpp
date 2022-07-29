#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	int w, h, x, y, p;
	int a, b; // � ������ x��ǥ = a, y��ǥ = b
	int len2L; // (������ ��ũ�� ���� �ݿ� ������ �Ÿ�) ^2
	int len2R; // (������ ��ũ�� ������ �ݿ� ������ �Ÿ�) ^2
	int cnt = 0, r2, r;

	cin >> w >> h >> x >> y >> p;
	r = h / 2;

	for (int i = 0; i < p; i++) {
		cin >> a >> b;

		len2L = (x - a) * (x - a) + ((y + r) - b) * ((y + r) - b);
		len2R = ((x + w) - a) * ((x + w) - a) + (((y + r) - b) * ((y + r) - b));
		r2 = (h / 2) * (h / 2);

		// ������ ���� �� ���ʿ� �ִ� ���
		if (len2L <= r2 || len2R <= r2) { cnt++; }
		// ������ �߰� �簢�� ���� �ȿ� �ִ� ���
		else if ((a >= x && b >= y) && (a <= x + w && b <= y + h)) { cnt++; }
	}
	cout << cnt;

	return 0;
}