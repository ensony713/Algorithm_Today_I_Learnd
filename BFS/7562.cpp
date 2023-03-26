#include <iostream>
#include <vector>
#define MAX 302
using namespace std;

class Point {
	int x;
	int y;
	int deep;

public:

	Point() {
		x = 0;
		y = 0;
		deep = 0;
	}

	Point(int n) {
		x = n;
		y = n;
		deep = 0;
	}

	Point(int n, int m) {
		x = n;
		y = m;
		deep = 0;
	}

	void deeper(int n) {
		deep = n;
	}
	
	void setX(int n) {
		x = n;
	}

	void setY(int n) {
		y = n;
	}

	int getD() {
		return deep;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	bool operator!= (Point n) {

		if (n.x == this->x && n.y == this->y) {
			return false;
		}
		return true;
	}

	bool operator== (Point n) {

		if (n.x == this->x && n.y == this->y) {
			return true;
		}
		return false;
	}

	Point operator+ (Point n) {

		Point tmp;
		tmp.x = n.x + this->x;
		tmp.y = n.y + this->y;

		return tmp;
	}

	bool in_map(int size) {
		if (x < 0 || x >= size) { return false; }
		if (y < 0 || y >= size) { return false; }
		return true;
	}
};

Point moving[] = { Point(-2, -1), Point(-1, -2),
				 Point(2, -1),  Point(1, -2),
				 Point(-2, 1),  Point(-1, 2),
				 Point(2, 1),   Point(1, 2) };

int bfs(int l, Point now, Point dest) {

	bool visite[MAX][MAX] = { 0 };
	vector<Point> works;
	Point tmp(now.getX(), now.getY()), newP;

	works.push_back(now);
	visite[now.getX()][now.getY()] = true;

	while (!works.empty() && tmp != dest) {

		tmp = works.front();
		works.erase(works.begin());

		for (int i = 0; i < 8; i++) {
			newP = tmp + moving[i];
			newP.deeper(tmp.getD() + 1);

			if (newP.in_map(l) && !visite[newP.getX()][newP.getY()]) {
				works.push_back(newP);
				visite[newP.getX()][newP.getY()] = true;
			}
		}
	}

	return tmp.getD();
}

/* 1 4 0 3 0 0 */

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t, i, x, y, dx, dy;
	cin >> t;

	for (int j = 0; j < t; j++) {
		cin >> i;
		cin >> x >> y >> dx >> dy;
		cout << bfs(i, Point(x, y), Point(dx, dy)) << '\n';
	}

	return 0;
}