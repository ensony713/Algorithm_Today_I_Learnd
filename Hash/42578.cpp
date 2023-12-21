// 프로그래머스
// 코딩테스트 연습, 의상

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> closet;

    for (auto clothe : clothes) {

        // unordered_map::find는 map 내에 해당 key가 없으면 unordered_map::end를 반환함
        // c++20부턴 contains로 확인 가능
        if (closet.end() == closet.find(clothe[1])) {
            closet[clothe[1]] = 1;
        }
        else {
            closet[clothe[1]]++;
        }
    }

    for (auto c : closet) {
        answer *= c.second + 1;
    }

    return --answer;
}