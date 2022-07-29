#include <iostream>
#include <cmath>
using namespace std;

struct point {
	int x, y;
};

struct circle {
	int r, x, y;
};

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n, cnt = 0;
	int len_s, len_e; // ���������� �༺�� �߽ɱ����� �Ÿ�, ���������� �༺�� �߽ɱ����� �Ÿ�
	point start, end; // ������, ������
	circle plant_sys; // �༺��
	int r2;

	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		cnt = 0;
		cin >> start.x >> start.y >> end.x >> end.y;

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> plant_sys.x >> plant_sys.y >> plant_sys.r;

			len_s = (plant_sys.x - start.x) * (plant_sys.x - start.x) 
				+ (plant_sys.y - start.y) * (plant_sys.y - start.y);
			len_e = (plant_sys.x - end.x) * (plant_sys.x - end.x)
				+ (plant_sys.y - end.y) * (plant_sys.y - end.y);
			r2 = plant_sys.r * plant_sys.r;

			if (len_s <= r2 && len_e > r2) { cnt++; }
			if (len_e <= r2 && len_s > r2) { cnt++; }
		}

		cout << cnt << '\n';
	}
}