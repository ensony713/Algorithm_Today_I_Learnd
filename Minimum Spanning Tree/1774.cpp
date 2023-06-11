#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX 500000
using namespace std;

struct point {
    double x, y;
};

struct node {
    int p1, p2;
    double weight;
};

class Union {

    int root[MAX];

public:

    Union(int s) {
        for (int i = 1; i <= s; i++) {
            root[i] = i;
        }
    }

    int find(int idx) {

        if (root[idx] == idx) {
            return idx;
        }

        root[idx] = find(root[idx]);

        return root[idx];
    }

    void combin(int a, int b) {

        int ra = find(a);
        int rb = find(b);

        if (ra == rb) {
            return;
        }

        if (ra < rb) {
            root[ra] = rb;
        }
        else {
            root[rb] = ra;
        }
    }

    bool is_union(int a, int b) {

        if (find(a) == find(b)) {
            return true;
        }
        return false;
    }
};

double get_lenght(point a, point b) {

    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

bool sorted(node a, node b) {

    if (a.weight < b.weight) { return false; }
    return true;
}

double kruskal(vector<node>& nodes, Union& uf, int n) {

    sort(nodes.begin(), nodes.end(), sorted);
    double result = 0;

    while (!nodes.empty()) {

        node now = nodes.back();
        nodes.pop_back();

        if (uf.is_union(now.p1, now.p2)) {
            continue;
        }

        result += now.weight;
        uf.combin(now.p1, now.p2);
    }

    return result;
}

int main(int argc, char** argv) {

    point p[1002];
    vector<node> nodes;
    node tmp;
    int n, m, a, b;
    cin >> n >> m;

    Union uf(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;

        for (int j = 1; j < i; j++) {

            tmp.p1 = i;
            tmp.p2 = j;
            tmp.weight = get_lenght(p[i], p[j]);

            nodes.push_back(tmp);
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        uf.combin(a, b);
    }

    cout << fixed;
    cout.precision(2);
    cout << kruskal(nodes, uf, n) << '\n';

    return 0;
}
