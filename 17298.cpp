#include <iostream>
#include <stack>
#define MAX 1000005
using namespace std;

int N, answer[MAX] = { 0 }, A[MAX], index = 0, lbn = 1;
stack <int> st;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    while (1) {

        if (index >= N)
            break;

        if (st.empty()) {
            st.push(index++);
            lbn = st.top() + 1;
        }
        
        if (A[st.top()] >= A[lbn]) {
            st.push(index++);
            lbn = st.top() + 1;
        }
        else {
            answer[st.top()] = A[lbn];
            st.pop();
        }
    }

    while (!st.empty()) {
        answer[st.top()] = -1;
        st.pop();
    }

    for (int i = 0; i < N; i++)
        cout << answer[i] << " ";
    cout << "\n";

    return 0;
}