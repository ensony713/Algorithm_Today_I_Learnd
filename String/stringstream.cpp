#include <sstream>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	
	string str = "c++ string stream test\nnewline,text";
	string tmp;

	stringstream sstream;
	// Ư�� string�� �Է����� �ϴ� stream ����

	sstream.str(str);

	// string stream�� >> �����ڴ� cin (Ű�����Է�)�� >> ������ó�� ' '�̳� '\n'�� �������� �о��
	while (sstream >> tmp) {
		cout << tmp << '\n';
	}

	/* ���
	c++
	string
	stream
	test
	newline,text
	*/

	return 0;
}