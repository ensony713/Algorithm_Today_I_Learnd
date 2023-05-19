#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <map>
using namespace std;

class UnionFind {

	map<char*, char*> parent;

public:

	void init() {
		parent.clear();
	}

	char* find(char name[]) {

		if (parent.find(name) == parent.end() || !strcmp(parent[name], name)) {
			return name;
		}

		parent[name] = find(parent[name]);
	}

	void combin(char a[], char b[]) {
		
		char* pa = find(a);
		char* pb = find(b);

		parent[pa] = pb;
	}

	bool is_union(char a[], char b[]) {
		
		if (!strcmp(find(a), find(b))) {
			return true;
		}
		return false;
	}

	int get_size() {
		return parent.size();
	}

	int count(char name[]) {

		int cnt = 0;
		for (auto& m : parent) {
			if (is_union(name, m.first)) {
				cnt++;
			}
		}

		return cnt;
	}
};

int main(int argc, char** argv) {
	
	int n, T;
	char a[25], b[25];

	scanf("%d", &T);
	
	UnionFind uf;

	while (T--) {

		uf.init();

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s %s", a, b);
			uf.combin(a, b);
			printf("%d\n", uf.count(a));
		}
	}

	return 0;
}