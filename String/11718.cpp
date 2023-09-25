#include<iostream>
using namespace std;

int main(int argc, char** argv) {

	char input[102];
	
	while (true) {
		cin.getline(input, 100);
		// cin.getline도 basic_istream::getline(str, count, delimiter)을 호출하네 
		// 그럼 구분자 주는게 시간상 이득 아닌가
		
		if (cin.eof()) { break; }
		/* 
		bool eof() {
			return rdstate() & ios_base::eofbit;
		}
		_Mystate의 eofbit가 set 되어 있으면 true를 반환하게 되는 함수

		rdstate() {
			return _Mystate; // -> stream state 이거는 각 비트가 상태의 의미를 담고 있다
		}
		*/
		
		cout << input << '\n';
	}

	return 0;
}