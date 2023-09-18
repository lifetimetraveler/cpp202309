#include <iostream>
using namespace std;

int main()
{
	int number;//변수선언
	cout << "숫자를 입력하시오.";
	cin >> number;//입력 받은 수로 초기화
	if (number == 0)//number가 0이면 true
		cout << "zero\n";//각 수에 맞는 영어 출력    \n은 줄 바꿈
	else if (number == 1)//number가 1이면 true
		cout << "one\n";
	else// 그 외의 나머지 경우 many출력
		cout << "many\n";
		return 0;
}