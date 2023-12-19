// 프로그래머스
// 연속된 부분 수열의 합
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int INF = 1000005;

// two pointer
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, 0);

    answer[1] = INF;

    int start = 0, end = 0;
    int total = 0;

    while (start < sequence.size() && end <= sequence.size()) {

        if (total < k) {
            total += sequence[end++];
        }

        if (total > k) {
            total -= sequence[start++];
        }

        if (total == k) {
            //cout << start << ", " << end - 1 << '\n';

            if ((answer[1] - answer[0] + 1) > (end - start)) {

                answer[0] = start;
                answer[1] = end - 1;
            }

            total -= sequence[start++];
        }
    }

    return answer;
}