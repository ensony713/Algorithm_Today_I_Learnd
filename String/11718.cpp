#include<iostream>
using namespace std;

int main(int argc, char** argv) {

	char input[102];
	
	while (true) {
		cin.getline(input, 100);
		// cin.getline�� basic_istream::getline(str, count, delimiter)�� ȣ���ϳ� 
		// �׷� ������ �ִ°� �ð��� �̵� �ƴѰ�
		
		if (cin.eof()) { break; }
		/* 
		bool eof() {
			return rdstate() & ios_base::eofbit;
		}
		_Mystate�� eofbit�� set �Ǿ� ������ true�� ��ȯ�ϰ� �Ǵ� �Լ�

		rdstate() {
			return _Mystate; // -> stream state �̰Ŵ� �� ��Ʈ�� ������ �ǹ̸� ��� �ִ�
		}
		*/
		
		cout << input << '\n';
	}

	return 0;
}