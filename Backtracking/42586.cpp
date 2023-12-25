// 프로그래머스
// 코딩테스트 연습, 기능개발

#include <string>
#include <vector>
using namespace std;

int get_release_day(int progress, int speed) {

    int days = (100 - progress) / speed;

    if ((100 - progress) % speed != 0) {
        days++;
    }

    return days;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    vector<int> complete;
    bool comp[105] = { 0 };

    for (int i = 0; i < progresses.size(); i++) {

        if (!comp[i]) {

            // i번째 기능의 배포 가능일
            int days_i = get_release_day(progresses[i], speeds[i]);

            for (int j = i; j < progresses.size(); j++) {

                if (!comp[j] && (j == 0 || comp[j - 1])) {

                    // j번째 기능의 배포 가능일
                    int days_j = get_release_day(progresses[j], speeds[j]);

                    if (days_j <= days_i) {
                        comp[j] = true;
                        complete.push_back(j);
                    }
                }
            }
        }

        if (complete.size() != 0) {
            answer.push_back(complete.size());
        }
        complete.clear();
    }

    return answer;
}