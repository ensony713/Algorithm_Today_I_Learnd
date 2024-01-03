// 프로그래머스
// 예상 대진표

#include <iostream>
using namespace std;

int solution(int n, int a, int b) {
    int answer = 0;

    // 트리 탐색 문제?
    // 최소 공통 조상 찾기 (LCA)
    // 깊이가 같은 곳에서 시작해서 선형시간 걸리는 DFS로 해결해도 됨 -> 하나씩 부모를 확인해가며 갱신
    // 근데 이 문제는 완전 이진 트리라서 log(n) 걸리겠다

    // 전처리 - 각 a와 b를 알맞은 index로 바꾸기
    int poa = n + a - 1, pob = n + b - 1;

    // 같을 때까지 부모를 확인하기
    while (poa != pob) {
        poa /= 2;
        pob /= 2;
        answer++;
    }

    return answer;
}