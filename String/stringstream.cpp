#include <sstream>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	
	string str = "c++ string stream test\nnewline,text";
	string tmp;

	stringstream sstream;
	// 특정 string을 입력으로 하는 stream 생성

	sstream.str(str);

	// string stream의 >> 연산자는 cin (키보드입력)의 >> 연산자처럼 ' '이나 '\n'을 기준으로 읽어옴
	while (sstream >> tmp) {
		cout << tmp << '\n';
	}

	/* 출력
	c++
	string
	stream
	test
	newline,text
	*/

	return 0;
}