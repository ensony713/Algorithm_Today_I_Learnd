#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    
    // attacks[i][0] = 시각, attacks[i][1] = 공격력

    int hp = health;
    int last = attacks[attacks.size() - 1][0];
    int idx = 0;
    int cnt = 0;

    // attacks가 정렬되어서 들어오나?
    

    for (int time = 1; time <= last; time++) {
        
        cout << hp << '\n';

        if (attacks[idx][0] == time) {

            hp -= attacks[idx][1];
            cnt = 0;

            cout << "attack! -" << attacks[idx][1] << '\n';
            idx++;
        }
        else {

            cout << "heal +" << bandage[1] << '\n';
            cnt++;
            hp += bandage[1];
            
            if (cnt == bandage[0]) {
                hp += bandage[2];
                cnt = 0;

                cout << "bonus +" << bandage[2] << '\n';
            }

            // 최댓값이 health만큼 되게
            hp = min(health, hp);
        }

        cout << " = " << hp << '\n';
        cout << "===============================\n";

        if (hp < 1) { return -1; }
    }

    return hp;
}

int main(int argc, char** argv) {

    vector<int> bandage(3);
    int health;
    vector<vector<int>> attacks;

    cin >> bandage[0] >> bandage[1] >> bandage[2];

    cin >> health;

    while (true) {
        int a, b;

        cin >> a >> b;

        if (a == 0 || b == 0) {
            break;
        }

        attacks.push_back({ a, b });
    }

    cout << solution(bandage, health, attacks);

    return 0;
}