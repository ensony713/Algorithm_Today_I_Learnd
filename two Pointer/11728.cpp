#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> result, A, B;
    int N, M, input;
    vector<int>::iterator ptrA, ptrB;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> input;
        A.push_back(input);
    }
    ptrA = A.begin();

    for (int i = 0; i < M; i++) {
        cin >> input;
        B.push_back(input);
    }
    ptrB = B.begin();

    while (ptrA != A.end() && ptrB != B.end()) {

        if (*ptrA <= *ptrB) {
            result.push_back(*ptrA);
            ptrA++;
        }
        else {
            result.push_back(*ptrB);
            ptrB++;
        }
    }

    if (ptrA != A.end()) {
        result.insert(result.end(), ptrA, A.end());
    }

    if (ptrB != B.end()) {
        result.insert(result.end(), ptrB, B.end());
    }

    for (auto& a : result) {
        cout << a << " ";
    }

    return 0;
}
