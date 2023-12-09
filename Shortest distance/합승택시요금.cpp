// 프로그래머스
// 2021 KAKAO BLIND RECRUITMENT, 합승 택시 요금

#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int MAX = 205;
const int INF = 100000 * MAX;

void show(vector<vector<int>>& costs) {

    for (auto i : costs) {
        for (auto j : i) {
            if (j == INF) {
                cout << "INF\t";
            }
            else {
                cout << j << '\t';
            }
        }
        cout << '\n';
    }
}

vector<vector<int>> floyd_warshall(int n, vector<vector<int>>& fares) {

    vector<vector<int>> costs;

    // costs[0][i]는 비워야
    costs.push_back({ INF });

    for (int i = 0; i < n; i++) {
        vector<int> idx(n + 1, INF);
        costs.push_back(idx);
    }

    // vector형태의 가중치를 costs 행렬에 집어넣기
    for (int i = 0; i < fares.size(); i++) {
        costs[fares[i][0]][fares[i][1]] = fares[i][2];
        costs[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                if (i != j && (costs[i][j] > costs[i][k] + costs[k][j])) {
                    costs[i][j] = costs[i][k] + costs[k][j];
                }
            }
        }
    }

    return costs;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    vector<vector<int>> costs = floyd_warshall(n, fares);

    int privately, share = INF;

    privately = costs[s][a] + costs[s][b];

    for (int i = 1; i <= n; i++) {

        int s_i = s == i ? 0 : costs[s][i];
        int i_a = i == a ? 0 : costs[i][a];
        int i_b = i == b ? 0 : costs[i][b];

        share = share < (s_i + i_a + i_b) ? share : (s_i + i_a + i_b);
    }

    if (privately < share) {
        return privately;
    }
    return share;
}