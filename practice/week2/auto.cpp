#include<iostream>
using namespace std;

auto add(int x, int y)//auto를 사용해서 컴파일러가 자동으로 반환형 지정 및 함수 선언
{
	return x + y;
}

int main()//만들어낸 함수를 이용해서 sum함수를 불러와서 계산
{
	auto sum = add(5, 6);
	cout << sum;
	return 0;
}