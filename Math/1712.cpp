#include <iostream>
using namespace std;

int main() {
	long long p_exp,  prodect, price,  BEP = 0,    exp_sum,				pure; //순이익
		//  고정지출, 생산비용,  가격, 손익분기점, 단일 생산 시 합계 지출

	cin >> p_exp >> prodect >> price;
	exp_sum = p_exp + prodect;
	pure = price - prodect;

	if (pure <= 0) {
		cout << -1;
		return 0;
	}

	BEP = p_exp / pure;
	BEP++;
	
	cout << BEP;
	return 0;
}