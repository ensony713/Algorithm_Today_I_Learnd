#include <iostream>
#include <limits>
#define MAX 404
using namespace std;

typedef struct node {
    int idx;
    int cost;
};

void f_w(int v, int result[][MAX]) {

    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {

                if (i == j) { continue; }

                if (result[i][k] != numeric_limits<int>::max() && result[k][j] != numeric_limits<int>::max() &&
                    result[i][j] > result[i][k] + result[k][j]) {
                    result[i][j] = result[i][k] + result[k][j];
                }
            }
        }
    }
}

int find_mini(int result[][MAX], int v) {

    int mini = numeric_limits<int>::max();

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {

            if (i == j) { continue; }

            if (result[i][j] != numeric_limits<int>::max() && result[j][i] != numeric_limits<int>::max()
                && mini > result[i][j] + result[j][i]) {
                mini = result[i][j] + result[j][i];
            }
        }
    }

    return mini;
}

int main(int argc, char** argv) {

    int v, e, a, b, c, answer;
    node input;
    int result[MAX][MAX];
    cin >> v >> e;

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i == j) {
                result[i][j] = 0;
            }
            else {
                result[i][j] = numeric_limits<int>::max();
            }
        }
    }

    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;

        result[a][b] = c;
    }

    f_w(v, result);

    answer = find_mini(result, v);

    if (answer != numeric_limits<int>::max()) {
        cout << answer;
    }
    else {
        cout << -1;
    }

    return 0;
}
