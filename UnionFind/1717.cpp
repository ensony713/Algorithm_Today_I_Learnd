#include <iostream>
#define MAX 1000005
using namespace std;

class UnionSet {

    int parent[MAX];

public:

    int get_parent(int a) {
        return parent[a];
    }

    UnionSet(int n) {

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    void combin(int a, int b) {

        a = find(a);
        b = find(b);

        if (a == b) { return; }

        if (a < b) {
            parent[b] = a;
        }
        else {
            parent[a] = b;
        }
    }

    bool is_union(int a, int b) {

        int pa = find(a);
        int pb = find(b);

        return pa == pb;
    }

    int find(int a) {

        if (parent[a] != a) {
            parent[a] = find(parent[a]);
        }

        return parent[a];
    }
};

int main(int argc, char* argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b;
    bool commend;

    cin >> n >> m;

    UnionSet us(n);

    for (int i = 0; i < m; i++) {

        cin >> commend >> a >> b;

        if (commend) {
            if (us.is_union(a, b)) {
                cout << "yes\n";
            }
            else {
                cout << "no\n";
            }
        }
        else {
            us.combin(a, b);
        }
    }

    return 0;
}