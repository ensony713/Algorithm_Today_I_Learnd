#include <iostream>
using namespace std;

int main() {
    char input[1000000] = { 0, };
    int alphabet[26] = { 0, }, max = 0, index;

    cin >> input;

    for (char a : input) {
        if (a >= 97) {
            a = (char) ((int) a - 32);
        }
        alphabet[(int)a - 65]++;
    }

    for (int i = 0; i < 26; i++) {
        if (max < alphabet[i]) {
            max = alphabet[i];
            index = i;
        } else if (max == alphabet[i]) {
            index = -2;
        }
    }

    cout << (char) (index + 65);
    return 0;
}