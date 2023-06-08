#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define MAX 5000
using namespace std;

struct point {
    double x, y;
};

point p[102];

double get_lenght(point& p1, point& p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

struct node {
    // p[x]의 별과, p[y] 별 사이의 거리 weight
    int p1, p2;
    double weight;
};

bool sorted (node a, node b) {
    if (a.weight < b.weight) { return false; }
    return true;
}

class Union {

    int root[MAX] = { 0 };

public:

    Union(int n) {

        for (int i = 1; i <= n; i++) {
            root[i] = i;
        }
    }

    void combin(int a, int b) {

        a = find(a);
        b = find(b);

        if (a == b) { return; }

        if (a < b) {
            root[b] = a;
        }
        else {
            root[a] = b;
        }
    }

    bool is_union(int a, int b) {

        int pa = find(a);
        int pb = find(b);

        return pa == pb;
    }

    int find(int a) {

        if (root[a] != a) {
            root[a] = find(root[a]);
        }

        return root[a];
    }
};

double kruskal(vector<node>& line, int n) {

    double result = 0;
    Union uf(n + 1);

    sort(line.begin(), line.end(), sorted );

    while (!line.empty()) {
        
        node now = line.back();
        line.pop_back();
        
        if (uf.is_union(now.p1, now.p2)) {
            continue;
        }

        uf.combin(now.p1, now.p2);
        result += now.weight;
    }

    return result;
}

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    double x, y;
    
    vector<node> line;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        p[i].x = x;
        p[i].y = y;

        for (int j = 0; j < i; j++) {
            node tmp;
            tmp.p1 = i;
            tmp.p2 = j;
            tmp.weight = get_lenght(p[i], p[j]);

            line.push_back(tmp);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << kruskal(line, n);

    return 0;
}
