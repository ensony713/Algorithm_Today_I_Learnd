// 프로그래머스
// PCCP 기출문제 2번 / 석유시추

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 502;

int oil[MAX][MAX] = { 0 }; // 석유 덩어리 번호
int cash[(MAX * MAX) / 2 + 1] = { 0 }; // 석유 덩어리 번호가 얼마큼의 양인지 저장
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

// [x][y]에서 시작하는 석유의 양을 계산하는 BFS
int bfs(int x, int y, vector<vector<int>>& land, int num) {

    queue<pair<int, int>> works;
    int cnt = 1;

    works.push({ x, y });
    oil[x][y] = num;

    while (!works.empty()) {

        int f = works.front().first;
        int s = works.front().second;
        works.pop();

        for (int i = 0; i < 4; i++) {

            int idx_x = f + dx[i];
            int idx_y = s + dy[i];

            // 범위 벗어난 거 예외처리
            if (idx_x < 0 || idx_x >= land.size() || idx_y < 0 || idx_y >= land[0].size()) {
                continue;
            }

            if (land[idx_x][idx_y] && !oil[idx_x][idx_y]) {
                works.push({ idx_x, idx_y });
                oil[idx_x][idx_y] = num;
                cnt++;
            }
        }
    }

    cash[num] = cnt;
    return cnt;
}

void show(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << oil[i][j] << ' ';
        }
        cout << '\n';
    }
}

int solution(vector<vector<int>> land) {

    int answer = 0;
    int cnt, num = 1;

    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[i].size(); j++) {
            if (land[i][j] && !oil[i][j]) {
                bfs(i, j, land, num++);
            }
        }
    }

    for (int i = 0; i < land[0].size(); i++) {

        bool visite[(MAX * MAX) / 2 + 1] = { 0 };
        cnt = 0;

        for (int j = 0; j < land.size(); j++) {
            if (!visite[oil[j][i]]) {
                cnt += cash[oil[j][i]];
                visite[oil[j][i]] = true;
            }
        }

        answer = answer < cnt ? cnt : answer;
    }

    /*
    cout << "기름의 양\n";
    for (int i = 0; i < num; i++) {
        cout << cash[i] << ' ';
    }
    cout << "\n\n";

    show(land.size(), land[0].size());
    */

    return answer;
}