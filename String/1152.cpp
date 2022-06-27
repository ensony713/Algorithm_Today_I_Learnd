#include <iostream>
#define MAX 1000002
using namespace std;

int main() {
    char input[MAX] = { 0 };
    int counter = 1, size = 0;

    cin.getline(input, MAX);

    for (int i = 0; i < MAX; i++) {
        if (input[i] == ' ') {
            counter++;
        }
        
        size = i;
        if (input[i] == 0) {
            break;
        }
    }

    if (input[0] == ' ') {
        counter--;
    }
    if (input[size - 1] == ' ') {
        counter--;
    }

    cout << counter;

    return 0;
}