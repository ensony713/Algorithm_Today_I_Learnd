#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#define MAX 502
using namespace std;

bool bfs(int start, int n, int l, bool visite[], vector<vector<int>>& gr) {

    queue<pair<int, int>> qu;
    // 현재 노드 번호, 해당 노드를 작업큐에 넣은 노드 번호

    qu.push({ start, 0 });

    while (!qu.empty()) {

        pair<int, int> node = qu.front();
        qu.pop();
        visite[node.first] = true;

        for (auto& a : gr[node.first]) {
            if (visite[a] && node.second != a) {
                return false;
            }
            else if (!visite[a]) {
                qu.push({ a, node.first });
            }
        }
    }

    return true;
}

void setVisite(bool visite[], int n) {

    for (int i = 0; i <= n; i++) {
        visite[i] = false;
    }
}

int findNext(bool visite[], int n) {

    for (int i = 1; i <= n; i++) {
        if (!visite[i]) {
            return i;
        }
    }

    return -1;
}

int findTree(int n, int l, bool visite[], vector<vector<int>>& gr) {

    int cnt = 0;
    int next = 1;

    while (next != -1) {

        if (bfs(next, n, l, visite, gr)) {
            cnt++;
        }

        next = findNext(visite, n);
    }

    return cnt;
}

void input(int n, int l, vector<vector<int>>& gr) {

    int a, b;

    gr.clear();
    gr.resize(n + 1);
    for (int i = 0; i < l; i++) {
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream ifs("C:\\Users\\seonu\\Documents\\input.txt");

    int T = 1, n, l, cnt;
    int a, b;
    vector<vector<int>> gr;
    bool visite[MAX];

    while (true) {

        cin >> n >> l;
        //ifs >> n >> l;

        if (n == 0 && l == 0) { break; }

        setVisite(visite, n);

        /*
        gr.clear();
        gr.resize(n + 1);
        for (int i = 0; i < l; i++) {
            ifs >> a >> b;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        */
        input(n, l, gr);

        cnt = findTree(n, l, visite, gr);

        cout << "Case " << T++ << ": ";

        if (cnt == 0) {
            cout << "No trees.\n";
        }
        else if (cnt == 1) {
            cout << "There is one tree.\n";
        }
        else {
            cout << "A forest of " << cnt << " trees.\n";
        }
    }

    return 0;
}
