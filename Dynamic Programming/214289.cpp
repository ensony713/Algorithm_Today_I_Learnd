// 프로그래머스
// 2023 현대모비스 알고리즘 경진대회 예선, 에어컨

#include <string>
#include <vector>
using namespace std;

const int INF = 200 * 1000;
const int ten = -10;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = INF;

    int point = temperature < t1 ? -1 : 1;
    int dy[] = { point, 0, point * -1 };
    int dx[] = { a, b, 0 };

    int max = t2 < temperature ? temperature - ten : t2 - ten;
    int cash[1002][52] = { 0 };
    // 오늘의 교훈, 메모리에서 +1은 위험하다...

    for (int i = 0; i <= onboard.size(); i++) {
        for (int j = 0; j <= max + 1; j++) {
            cash[i][j] = INF;
        }
    }

    cash[0][temperature - ten] = 0;

    for (int i = 0; i < onboard.size(); i++) {

        for (int j = 0; j <= max; j++) {

            // 승객이 있는데 j가 온도를 벗어난 경우
            if (onboard[i] && (t1 > j + ten || t2 < j + ten)) {
                cash[i][j] = INF;
                continue;
            }

            for (int k = 0; k < 3; k++) {

                int di = i - 1; // 이전 시각
                int dj = j + dy[k]; // 온도

                // 범위를 벗어난 경우
                if (di < 0 || dj < 0 || dj > max) { continue; }

                // 에어컨을 끄고 온도가 유지되는 경우
                else if (j + ten == temperature) {
                    cash[i][j] = cash[di][dj] < cash[i][j] ? cash[di][dj] : cash[i][j];
                }

                // 온도가 변화되는 상황(temp < t1 && t2 < temp)에서 에어컨을 끄거나 켤 경우
                else if (cash[di][dj] + dx[k] < cash[i][j]) {
                    cash[i][j] = cash[di][dj] + dx[k];
                }
            }
        }
    }

    for (int i = 0; i <= max; i++) {
        answer = answer < cash[onboard.size() - 1][i] ? answer : cash[onboard.size() - 1][i];
    }

    return answer;
}