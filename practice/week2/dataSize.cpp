#include<iostream>

using namespace std;

int main()
{
	cout << "char 크기 : " << sizeof('p') << endl;//각 자료형의 크기를 출력하는 sizeof사용
	cout << "int 크기 : " << sizeof(10) << endl;//그 결과 자료형에맞는 크기 출력
	cout << "double 크기 : " << sizeof(10.0) << endl;

	return 0;
}