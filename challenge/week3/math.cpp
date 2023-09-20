#include<iostream>
#include<time.h>
using namespace std;

int main()
{
	int i;
	int ans;
	cout << "산수 문제를 자동으로 출제합니다." << endl;

	while (true) {
		int firstNum = rand() % 100;//랜덤으로 두 수 생성
		int secondNum = rand() % 100;

		cout << firstNum << "+" << secondNum << "=";//랜덤의 두수 출력
		cin >> ans;
		if (firstNum + secondNum == ans) {//수의 합이 맞을 경우
			cout << "맞았습니다." << endl;//맞았습니다 출력후 탈출
			break;
		}
		else {
			cout << "틀렸습니다." << endl;//그 나머지인 틀린 경우에는 다시 while문의 반복
		}
	}
	return 0;
}