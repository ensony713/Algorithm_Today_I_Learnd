#include <iostream>
#include <limits>
#define MAX 102
using namespace std;

void floyd_warshall(long gr[][MAX], int v) {

    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {

                if (i != j && gr[i][j] > gr[i][k] + gr[k][j]) {
                    gr[i][j] = gr[i][k] + gr[k][j];
                }
            }
        }
    }
}

void init(long gr[][MAX], int v, int x) {

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            gr[i][j] = x;
        }
    }
}

void print(long gr[][MAX], int v, int maxi) {

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (gr[i][j] == maxi) {
                cout << 0 << ' ';
            }
            else {
                cout << gr[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}

int main(int argc, char** argv) {

    int v, e, a, b, c;
    long graphe[MAX][MAX];

    cin >> v >> e;

    init(graphe, v, numeric_limits<int>::max());

    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        graphe[a][b] = graphe[a][b] > c ? c : graphe[a][b];
    }

    floyd_warshall(graphe, v);

    print(graphe, v, numeric_limits<int>::max());

    return 0;
}