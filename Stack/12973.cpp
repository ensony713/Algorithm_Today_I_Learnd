// 프로그래머스
// stack

#include <string>
#include <vector>
using namespace std;

int solution(string s) {

    vector<char> stack;

    stack.push_back(s[0]);

    for (int i = 1; i < s.size(); i++) {

        if (stack.size() != 0 && stack.back() == s[i]) {
            stack.pop_back();
        }
        else {
            stack.push_back(s[i]);
        }
    }

    if (stack.size() == 0) {
        return 1;
    }
    return 0;
}
