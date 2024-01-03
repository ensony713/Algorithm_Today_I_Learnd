// ���α׷��ӽ�
// ���� ����ǥ

#include <iostream>
using namespace std;

int solution(int n, int a, int b) {
    int answer = 0;

    // Ʈ�� Ž�� ����?
    // �ּ� ���� ���� ã�� (LCA)
    // ���̰� ���� ������ �����ؼ� �����ð� �ɸ��� DFS�� �ذ��ص� �� -> �ϳ��� �θ� Ȯ���ذ��� ����
    // �ٵ� �� ������ ���� ���� Ʈ���� log(n) �ɸ��ڴ�

    // ��ó�� - �� a�� b�� �˸��� index�� �ٲٱ�
    int poa = n + a - 1, pob = n + b - 1;

    // ���� ������ �θ� Ȯ���ϱ�
    while (poa != pob) {
        poa /= 2;
        pob /= 2;
        answer++;
    }

    return answer;
}