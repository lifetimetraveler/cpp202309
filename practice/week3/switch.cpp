#include<iostream>
using namespace std;

int main()
{
	int number = 3;
	switch (number) {
	case 1:
		cout << "number 값은 1입니다." << endl;
		break;
	case 2:
		cout << "number 값은 2입니다." << endl;
		break;
	case 3://number 가 3일 경우에 그 아래부터 다 실행. 그러나 break에서 탈출
		cout << "number 값은 3입니다." << endl;
		break;
	default://할당 되지 않은 경우에는 아래를 실행
		cout << "number 값을 알 수 없습니다." << endl;
		break;
	}
	return 0;
}