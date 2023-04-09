#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {

    int n, x, input, result = 0, sum;
    vector<int> nums;
    vector<int>::iterator start, end;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        nums.push_back(input);
    }

    cin >> x;

    sort(nums.begin(), nums.end());

    start = nums.begin();
    end = nums.end() - 1;

    while (start != end) {

        sum = *start + *end;

        if (sum == x) {
            result++;
        }

        if (sum < x) {
            start++;
        }
        else {
            end--;
        }
    }

    cout << result;

    return 0;
}