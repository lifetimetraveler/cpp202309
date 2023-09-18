#include<iostream>
using namespace std;

int main()
{
	int a, b, c, largest;//4 개의 변수 선언
	
	cout << "3 개의 정수를 입력하십시오: ";
	cin >> a >> b >> c;//3 개의 변수 선언

	if (a > b && a > c)//a가 b나 c보다 크면 1 두 조건 만족시 1
		largest = a;
	else if (b > a && b > c)//b가 a나 c보다 크면 1, 다 만족해야 1
		largest = b;
	else//그 외의 경우. c가 가장 크면 1 
		largest = c;
	//각 조건 만족시 largest를 그 변수로 초기화
	cout << "가장 큰 정수는" << largest << endl;
	return 0;
}