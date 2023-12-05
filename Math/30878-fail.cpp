#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int m;
	cin >> m;
	
	// m / 60 을 기약분수 형태로 나타내면 되는거 아닌가
	// 공약수 찾기
	
	int base = 60;
	for (int common = m; common > 1; common--) {
	    
	    if ((m % common == 0) && (base % common == 0)) {    
	        m /= common;
	        base /= common;
	    }
	}
	
	cout << m << "/" << base << '\n';
	
	return 0;
}
