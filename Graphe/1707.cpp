#include <iostream>
#include <vector>
#define MAX 20002
using namespace std;

void bfs(int start, int size, vector<vector<int>> graphe, bool visite[], bool A[]) {

    vector<int> works;
    int node;
    bool sw = true;

    works.push_back(start);
    visite[start] = true;
    A[start] = sw;

    while (!works.empty()) {

        node = works.front();
        works.erase(works.begin());
        sw = !A[node];

        for (auto& l : graphe[node]) {
            if (!visite[l]) {
                visite[l] = true;
                works.push_back(l);
                A[l] = sw;
            }
        }
    }
}

bool is_binary(int size, vector<vector<int>> graphe) {

    bool visite[MAX] = { 0 };
    bool A[MAX] = { 0 };

    for (int i = 1; i <= size; i++) {
        if (!visite[i]) {
            bfs(i, size, graphe, visite, A);
        }
    }

    for (int i = 1; i <= size; i++) {
        for (auto& j : graphe[i]) {
            if (A[i] == A[j]) {
                return false;
            }
        }
    }

    return true;
}

int main(int argc, char** argv) {

    int k, v, e, a, b;
    vector<vector<int>> graphe;
    cin >> k;

    while (k--) {

        cin >> v >> e;

        graphe.clear();
        graphe.resize(v + 1);

        for (int i = 0; i < e; i++) {
            cin >> a >> b;
            graphe[a].push_back(b);
            graphe[b].push_back(a);
        }

        if (is_binary(v, graphe)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}