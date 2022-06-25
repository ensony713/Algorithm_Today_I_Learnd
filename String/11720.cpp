#include <iostream>
using namespace std;

int main() {

    int N, sum = 0;
    cin >> N;

    cin.get();

    for (int i = 0; i < N; i++)
        sum += cin.get() - 48;

    cout << sum;

    return 0;
}