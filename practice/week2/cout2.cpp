#include<iostream>
#include<string>

using namespace std;

int main()
{
	char character = 'C';//char 문자 int 정수 double bool 논리형 string 문자열
	int integer = 100;//각 자료형에 대한 맞는 값 할당
	double precision = 3.14159;
	bool is_true = true;
	string word = "Hello World";

	cout << "char : " << character << endl;// 결과값 출력
	cout << "int : " << integer << endl;
	cout << "double : " << precision << endl;
	cout << "bool : " << is_true << endl;
	cout << "string : " << word << endl;

	return 0;
}