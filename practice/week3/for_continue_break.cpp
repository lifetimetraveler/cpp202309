#include<iostream>

using namespace std;

int main()
{
	int number = 7;

	for (int i = 0; i < 10; i++)
	{
		if (i % 3 == 0)//나머지가 0일때 == 3의 배수일 때
			continue;//반복문의 처음으로 돌아감
		else if (i == number)//i가 7이 되면 반복문에서 탈출하게 됨
			break;
		else//3의 배수가 아닐 때만 i의 값이 출력이 됨
			cout << "현재 i값: " << i << endl;

	}
	return 0;
}