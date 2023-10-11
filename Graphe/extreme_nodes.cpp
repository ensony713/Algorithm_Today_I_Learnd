#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int MAX = 20000;

// vector에서 최고값 개수 반환
int counter(vector<int>& result) {

    int maxi = 0;
    int cnt = 0;
    for (int i = 1; i < result.size(); i++) {
        if (maxi < result[i]) {
            maxi = result[i];
            cnt = 1;
        }
        else if (maxi == result[i]) {
            cnt++;
        }
    }

    return cnt;
}

void bfs(int n, int start, vector<vector<int>>& edge, vector<int>& result) {

    bool visite[MAX] = { 0 };
    queue<pair<int, int>> work;
    // node index, 거쳐온 거리

    work.push({ start, 0 });
    visite[start] = true;
    result[start] = 0;

    while (!work.empty()) {

        int node = work.front().first;
        int distance = work.front().second;
        work.pop();

        for (int i = 0; i < edge.size(); i++) {

            int r = edge[i][0], l = edge[i][1];

            if (r == node && !visite[l]) {
                work.push({ l, distance + 1 });
                visite[l] = true;
                result[l] = distance + 1;
            }
            if (l == node && !visite[r]) {
                work.push({ r, distance + 1 });
                visite[r] = true;
                result[r] = distance + 1;
            }
        }
    }

    for (auto a : result) {
        cout << a << " ";
    }
    cout << '\n';
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<int> result(n + 1);

    bfs(n, 1, edge, result);

    answer = counter(result);

    return answer;
}

int main(int argc, char** argv) {

    int n, m, a, b;
    vector<vector<int>> edge;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        vector<int> tmp;
        tmp.push_back(a);
        tmp.push_back(b);

        edge.push_back(tmp);
    }

    cout << solution(n, edge) << '\n';

    return 0;
}