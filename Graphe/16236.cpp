#include <iostream>
#include <vector>
#define MAX 22
using namespace std;

typedef struct node {
	int x, y; // 현재 위치
	int deep = 0; // 지나온 칸 수
	int size = 2; // 크기
	int count = 0; // 먹은 물고기 수
};

bool operator> (node a, node b) {

	if (a.deep > b.deep) { return true; }

	if (a.deep < b.deep) { return false; }

	// deep이 같고
	if (a.x > b.x) { return true; }

	if (a.x < b.x) { return false; }

	// x가 같고
	if (a.y > b.y) { return true; }

	return false;
}

class Heap {
	int size = 0;
	node data[MAX * MAX] = { 0 };

public:

	void init() { size = 0; }

	int get_size() { return size; }

	void push(node x) {
		data[++size] = x;

		int idx = size;
		node tmp;

		while (idx > 0) {
			if (data[idx / 2] > data[idx]) {
				tmp = data[idx];
				data[idx] = data[idx / 2];
				data[idx / 2] = tmp;
			}
			else {
				break;
			}
		}
	}

	node pop() {

		node result = data[1], tmp;
		int idx = 1, right, left, t;

		data[1] = data[size--];

		while (idx <= size) {
			right = idx * 2 + 1;
			left = idx * 2;

			if (left > size) {
				break;
			}
			else if (right > size) {
				t = left;
			}
			else {
				t = data[right] > data[left] ? left : right;
			}

			if (data[idx] > data[t]) {
				tmp = data[idx];
				data[idx] = data[t];
				data[t] = tmp;
				idx = t;
			}
			else {
				break;
			}
		}

		return result;
	}

	void show() {

		for (int i = 1; i <= size; i++) {
			cout << data[i].x << "," << data[i].y << ":" << data[i].deep << '\n';
		}
	}
};

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

void show(int map[][MAX], int n) {

	cout << '\n';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0) cout << map[i][j] << ' ';
			else cout << '.' << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

bool possible(int map[][MAX], int n, node now) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] > 0 && map[i][j] < now.size) {
				return true;
			}
		}
	}

	return false;
}

bool can_eat(int fish, int size) {

	if (size > fish && fish > 0) { return true; }
	return false;
}

void eat(node& t) {

	t.count++;

	if (t.count == t.size) {
		t.count = 0;
		t.size++;
	}
}

void bfs(int map[][MAX], int n, node& start, Heap& h) {

	int max = 0, tmp = 0, base = start.count;
	node now = start, next;
	bool visite[MAX][MAX] = { 0 };
	vector<node> works;

	works.push_back(now);
	visite[now.x][now.y] = true;

	while (!works.empty() && now.count <= base) {

		now = works.front();
		works.erase(works.begin());

		if (can_eat(map[now.x][now.y], now.size)) {
			h.push(now);
		}

		for (int i = 0; i < 4; i++) {
			next.x = now.x + dx[i];
			next.y = now.y + dy[i];
			next.deep = now.deep + 1;
			next.count = now.count;
			next.size = now.size;
			
			if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n) {
				continue;
			}

			if (!visite[next.x][next.y] && map[next.x][next.y] <= now.size) {
				works.push_back(next);
				visite[next.x][next.y] = true;
			}
		}
	}
}

int main(int argc, char** argv) {

	int map[MAX][MAX] = { 0 };
	int n, input, output = 0;
	node start;
	Heap h;

	start.x = 0;
	start.y = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;

			if (input == 9) {
				start.x = i;
				start.y = j;
			}
			else if (input != 0) {
				map[i][j] = input;
			}
		}
	}

	while (possible(map, n, start)) {

		bfs(map, n, start, h);

		if (h.get_size() == 0) {
			break;
		}

		start = h.pop();
		output += start.deep;
		
		eat(start);
		start.deep = 0;
		map[start.x][start.y] = 0;
		h.init();
	}

	cout << output << '\n';

	return 0;
}