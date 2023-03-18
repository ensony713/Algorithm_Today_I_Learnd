#include <iostream>
#include <stack>
using namespace std;

bool is_ppap(stack<char>& st) {

    if (st.size() == 1 && st.top() == 'P') {
        st.pop();
        return true;
    }

    char conGroup[] = { 'P', 'A', 'P', 'P' };

    for (int i = 0; i < 4; i++) {

        if (st.empty()) {
            return false;
        }

        if (conGroup[i] != st.top()) {
            return false;
        }

        st.pop();
    }

    st.push('P');
    return true;
}

int main(int argc, char** argv) {

    stack<char> st;
    string input;
    char before;
    int count = 0;

    cin >> input;

    for (int i = 0; i < input.size(); i++) {

        st.push(input[i]);

        if (before == 'A' && input[i] == 'P' && !is_ppap(st)) {
            cout << "NP\n";
            return 0;
        }

        before = input[i];
    }

    while (!st.empty()) {
        if (!is_ppap(st)) {
            cout << "NP\n";
            return 0;
        }
    }

    cout << "PPAP\n";

    return 0;
}
