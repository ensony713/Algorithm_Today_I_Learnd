#include <iostream>
#define MAX 3002
#define NUM 3000002
using namespace std;

int indexing(int idx, int size) {
    idx += size;
    return idx %= size;
}

void show(int cate[], int N) {
    for (int i = 0; i < N; i++) {
        if (cate[i] > 0) {
            cout << i << ":" << cate[i] << " ";
        }
    }
    cout << '\n';
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, d, k, c, start, end, maxi = 0, count = 0, cupon = 0;
    int cate[MAX] = { 0 };
    int susi[NUM] = { 0 };

    cin >> N >> d >> k >> c;

    for (int i = 0; i < N; i++) {
        cin >> susi[i];
    }

    start = 0;
    end = k - 1;
    for (int i = start; i <= end; i++) {
        if (cate[susi[i]] < 1) {
            count++;
        }
        cate[susi[i]]++;
    }

    while (start < N) {

        if (cate[c] < 1) { cupon = 1; }
        else { cupon = 0; }
        maxi = maxi < count + cupon ? count + cupon : maxi;

        cate[susi[start]]--;
        if (cate[susi[start++]] < 1) {
            count--;
        }

        end = indexing(end + 1, N);
        if (cate[susi[end]] < 1) {
            count++;
        }
        cate[susi[end]]++;
    }

    cout << maxi << '\n';

    return 0;
}
