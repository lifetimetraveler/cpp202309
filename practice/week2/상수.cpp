#include<iostream>
#define PI 3.14159265359
using namespace std;

int main()
{
	int income = 1000;//인컴은 리터럴 상수여서 다음 줄 넘어갈떄 휘발
	const double TAX_RATE = 0.25;//상수 처리하여서 변하지 않음
	income = income - TAX_RATE * income;//상수가 아닌 income만 변화

	double x = 100;//마찬가지로 PI는 상수여서 변하지 않고 x만 변화
	x = x * PI;

	cout << x << endl;
	return 0;
}