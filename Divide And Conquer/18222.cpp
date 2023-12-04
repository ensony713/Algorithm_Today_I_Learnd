#include <iostream>
#include <cmath>
using namespace std;

// 0 = 0
// 1 = 01 -> 2
// 2 = 0110 -> 4
// 3 = 01101001 -> 8
// 4 = 0110100110010110 -> 16
// 5 = 01101001100101101001011001101001 -> 32
// 6 = 0110100110010110100101100110100110010110011010010110100110010110 -> 64
// 반으로 나누고 상대적 위치? 이럼 이분탐색 아닌감, 아 이건 문자열을 만들어야되네;
// 만드는건 실패임 10^18 까지라서... 자릿수로?

// ex) 3 f1 b1
// 0step > 0110 > 3 - 2 = 1 (back)
// 1step > 10 > 1 - 1 = 0 (front)
// 2step > 1

// ex) 5 f2 b1
// 0step > 01101001 > 5 - 4 = 1 (back)
// 1step > 1001 > 1 - 2 = -1 (front)
// 2step > 10 > 1 - 1 = 0 (front)
// 3step > 1

// ex) 8 f0 b3
// 0step > 01101001 > 8 - 4 = 4 (back)
// 1step > 1001 > 4 - 2 = 2 (back)
// 2step > 01 > 2 - 1 = 1 (back)
// 3step > 1

// ex) 56 f1 b5
// 0step > 0110100110010110100101100110100110010110011010010110100110010110 > 56 - 32 = 24 (back)
// 1step > 10010110011010010110100110010110 > 24 - 16 = 8 (back)
// 2step > 0110100110010110 > 8 - 8 = 0 (front)
// 3step > 01101001 > 8 - 4 = 4 (back)
// 4step > 1001 > 4 - 2 = 2 (back)
// 5step > 01 > 2 - 1 = 1 (back)
// 6step > 1



// ex) 13 f2 b2
// 0step > 0110100110010110 > (13 - 8) = 5 (back)
// 1step > 10010110 > (5 - 4) = 1 (back)
// 2step > 0110 > (1 - 2) = -1 (front)
// 3step > 01 > (1 - 1) = 0 (front)
// 4step > 0

// ex) 13을 1이 아니라 0부터 세면?
// 0step > 0110100110010110 > (13 - 8) = 5 (back) 2^3
// 1step > 10010110 > (5 - 4) = 1 (back) 2^2
// 2step > 0110 > (1 - 2) = -1 (front) 2^1
// 3step > 01 > (1 - 1) = 0 (back) 2^0
// 4step > 1

// ex) 6 f1 b2
// 0step > 01101001 > 6 - 4 = 2 (back)
// 1step > 1001 > 2 - 2 = 0 (front)
// 2step > 10 > 2 - 1 = 1 (back)
// 3step > 0

// ex) 7 f1 b2
// 0step > 01101001 > 7 - 4 = 3 (back)
// 1step > 1001 > 3 - 2 = 1 (back)
// 2step > 01 > 1 - 1 = 0 (front)
// 3step > 0

// ex) 16 f0 b4
// 0step > 0110100110010110 > 16 - 8 = 8 (back)
// 1step > 10010110 > 8 - 4 = 4 (back)
// 2step > 0110 > 4 - 2 = 2 (back)
// 3step > 10 > 2 - 1 = 1 (back)
// 4step > 0

// log_2 (k)를 올리면 시작해야 할 자릿수가 나옴
// 잔여 n < 1 일 때 자리수만큼 더해주기
// front로 시작하는 건 없다. 무조건 back으로 시작, front 수 상관 없이 
// back이 몇개냐에 따라 갈리는거 같은데? -> 짝수개 = 0, 홀수개 = 1

// 어 왜 k - 1의 이진 표현에서 1의 개수랑 back의 개수가 같냐????? 아. 이해함

typedef unsigned long long number;

//int back_counter(number k) {
//
//	number base = log2(k);
//	cout << base << '\n';
//	base = pow(2, base);
//	cout << base << '\n';
//	int back = 0;
//
//	while (base > 0) {
//		//cout << k << " - " << base << " = " << k - base << '\n';
//
//		if ((k - base) > 0) {
//			back++;
//		}
//
//		k -= base;
//		if (k <= 0) {
//			k += base;
//		}
//		base /= 2;
//	}
//
//	//cout << "b" << back << '\n';
//
//	return back;
//}

int back_counter(number k) {

	int cnt = 0;
	k--;

	while (k > 0) {

		if (k % 2 == 1) {
			cnt++;
		}
		k /= 2;
	}

	return cnt;
}

int main(int argc, char** argv) {
	
	number k;
	cin >> k;

	if ((back_counter(k) % 2) == 0) {
		cout << "0";
	}
	else {
		cout << "1";
	}

	return 0;
}