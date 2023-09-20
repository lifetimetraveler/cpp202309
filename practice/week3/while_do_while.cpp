#include<iostream>

using namespace std;

int main()
{
	int number = 0;
	while (number < 10)//괄호 안의 조건에 맞으면 계속 반복
	{
		number++;//반복 할 때마다 1씩 증가
		if (number % 3 == 0)//3으로 나눠서 나머지가 0일 때
			continue;//반복 문의 처음으로 돌아감
		else// 그 외의 경우에는 출력이 됨. number의 값이
			cout << "number 값 : " << number << endl;
	}
	return 0;
}