#include <iostream>

using namespace std;

int main()
{
	int two = 2;
	int eight = 8;
	int sum1 = 2;
	int sum2 = 8;

	sum1 *= two;//왼쪽에 오른쪽 값을 곱한값을 좌변에 다시 초기화시킨다
	sum2 /= eight;//왼쪽에 오른쪽 값을 나눈다. 그 값을 왼쪽 변에 초기화시킨다.

	cout << "sum1 = " << sum1 << endl;//결과 값 출력
	cout << "sum2 = " << sum2 << endl;

	return 0;
}