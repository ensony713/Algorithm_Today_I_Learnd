// ���α׷��ӽ�
// 2023 ������ �˰��� ������ȸ ����, ������

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
    // ������ ����, �޸𸮿��� +1�� �����ϴ�...

    for (int i = 0; i <= onboard.size(); i++) {
        for (int j = 0; j <= max + 1; j++) {
            cash[i][j] = INF;
        }
    }

    cash[0][temperature - ten] = 0;

    for (int i = 0; i < onboard.size(); i++) {

        for (int j = 0; j <= max; j++) {

            // �°��� �ִµ� j�� �µ��� ��� ���
            if (onboard[i] && (t1 > j + ten || t2 < j + ten)) {
                cash[i][j] = INF;
                continue;
            }

            for (int k = 0; k < 3; k++) {

                int di = i - 1; // ���� �ð�
                int dj = j + dy[k]; // �µ�

                // ������ ��� ���
                if (di < 0 || dj < 0 || dj > max) { continue; }

                // �������� ���� �µ��� �����Ǵ� ���
                else if (j + ten == temperature) {
                    cash[i][j] = cash[di][dj] < cash[i][j] ? cash[di][dj] : cash[i][j];
                }

                // �µ��� ��ȭ�Ǵ� ��Ȳ(temp < t1 && t2 < temp)���� �������� ���ų� �� ���
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