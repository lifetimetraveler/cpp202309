#include<iostream>

using namespace std;

int main()
{
	int two = 2;//네개의 변수 선언 및 초기화
	int eight = 8;
	int sum1 = 2;
	int sum2 = 2;

	sum1 = sum1 + two;
	sum2 += eight;//사칙연산을 축약해서 sum2에 eight을 더하는 형태
	cout << "sum1 = " << sum1 << endl;//결과값 출력
	cout << "sum2 = " << sum2 << endl;
	return 0;
}