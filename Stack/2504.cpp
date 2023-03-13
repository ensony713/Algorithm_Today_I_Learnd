#include <iostream>
#include <memory.h>
#define MAX 100
#define NOPE '0'
using namespace std;

typedef char node;

class Stack {
    int top;
    node data[MAX];

public:
    Stack() {
        top = 0;
        memset(data, 0, sizeof(data));
    }

    void init() {
        top = 0;
    }

    bool empty() {
        if (top == 0) { return true; }
        return false;
    }

    int size() {
        return top;
    }

    void push(node x) {
        data[top++] = x;
    }

    node pop() {
        if (empty()) {
            return NOPE;
        }
        return data[top--];
    }

    node get_top() {
        if (empty()) { return NOPE; }
        return data[top - 1];
    }

    node get_data(int i) {
        if (i >= top) { return NOPE; }
        return data[i];
    }
};

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string input;
    Stack st;
    node before = NOPE;
    long long tmp, result = 0;

    cin >> input;

    for (int i = 0; i < input.size(); i++) {

        if (input[i] == '(') {
            st.push(input[i]);
        }
        if (input[i] == '[') {
            st.push(input[i]);
        }

        if (input[i] == ')' && st.get_top() != '(') {
            cout << 0;
            return 0;
        }
        if (input[i] == ']' && st.get_top() != '[') {
            cout << 0;
            return 0;
        }

        if (input[i] == ']' || input[i] == ')') {
            st.pop();

            if ((before == '[' && input[i] == ']') || (before == '(' && input[i] == ')')) {
                tmp = input[i] == ']' ? 3 : 2;

                for (int j = 0; j < st.size(); j++) {
                    tmp *= st.get_data(j) == '(' ? 2 : 3;
                }
                result += tmp;
            }
        }

        before = input[i];
    }

    if (st.size() != 0) { cout << 0; }
    else { cout << result; }

    return 0;
}