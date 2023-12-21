// ���α׷��ӽ�
// �ڵ��׽�Ʈ ����, �ǻ�

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> closet;

    for (auto clothe : clothes) {

        // unordered_map::find�� map ���� �ش� key�� ������ unordered_map::end�� ��ȯ��
        // c++20���� contains�� Ȯ�� ����
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