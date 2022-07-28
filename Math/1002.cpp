#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
	double x, y; // ���� ��ǥ
	double r; // ������

	bool operator== (Point& p) {
		if (p.x == x && p.y == y) return true;
		return false;
	}

	// �� ���� ���� �� �Ÿ� ���ϱ�
	double getFar(Point& p) {
		double lx = abs(p.x - x);
		double ly = abs(p.y - y);

		return sqrt(pow(lx, 2) + pow(ly, 2));
	}
};

// double abs(double n) n�� ���밪 ��ȯ
// double pow(double r, int n) r�� n���� ��ȯ
// double sqrt(literal_number_type n) n�� ������ ��ȯ

int main(int argc, char* argv[]) {
	int T;
	double d, diff;
	// d = �� ���� ���� �� �Ÿ�
	// diff = |�� ���� ������ ����|

	Point p1, p2;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> p1.x >> p1.y >> p1.r >> p2.x >> p2.y >> p2.r;

		d = p1.getFar(p2);
		diff = abs(p1.r - p2.r);

		if (diff > d || p1.r + p2.r < d) cout << 0 << '\n';
		else if (p1 == p2) cout << -1 << '\n';
		else if (p1.r + p2.r == d || diff == d) cout << 1 << '\n';
		else cout << 2 << '\n';
	}
	return 0;
}