#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	int w, h, x, y, p;
	int a, b; // 어떤 선수의 x좌표 = a, y좌표 = b
	int len2L; // (선수와 링크의 왼쪽 반원 중점의 거리) ^2
	int len2R; // (선수와 링크의 오른쪽 반원 중점의 거리) ^2
	int cnt = 0, r2, r;

	cin >> w >> h >> x >> y >> p;
	r = h / 2;

	for (int i = 0; i < p; i++) {
		cin >> a >> b;

		len2L = (x - a) * (x - a) + ((y + r) - b) * ((y + r) - b);
		len2R = ((x + w) - a) * ((x + w) - a) + (((y + r) - b) * ((y + r) - b));
		r2 = (h / 2) * (h / 2);

		// 선수가 양쪽 원 안쪽에 있는 경우
		if (len2L <= r2 || len2R <= r2) { cnt++; }
		// 선수가 중간 사각형 범위 안에 있는 경우
		else if ((a >= x && b >= y) && (a <= x + w && b <= y + h)) { cnt++; }
	}
	cout << cnt;

	return 0;
}