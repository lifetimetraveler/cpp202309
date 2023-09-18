#include<iostream>
using namespace std;

int main()
{
	int a, b, c, smallest;//4 개의 변수 선언

	cout << "3 개의 정수를 입력하십시오: ";
	cin >> a >> b >> c;//3 개의 변수 선언

	if (a < b && a < c)//a가 b나 c보다 작으면 1 두 조건 만족시 1
		smallest = a;
	else if (b < a && b < c)//b가 a나 c보다 작으면 1, 다 만족해야 1
		smallest = b;
	else//그 외의 경우. c가 가장 작으면 1 
		smallest = c;
	//각 조건 만족시 smallest를 그 변수로 초기화
	cout << "가장 작은 정수는" << smallest << endl;//결과 값 출력
	return 0;
}