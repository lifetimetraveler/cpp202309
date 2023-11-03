#include <iostream>
using namespace std;

int main()
{//사탕과 돈의 수치를 받기 위한 변수 선언
	int money;
	int candy;

	//돈과 사탕을 입력 받음
	cout << "가지고 있는 돈 = " ;
	cin >> money;
	cout << "캔디의 가격 = " ;
	cin >> candy;




//돈과 사탕의 출력
	cout << "현재 가지고 있는 돈 : " << money<<endl;
	cout << "캔디의 가격 : " << candy<<endl;
	//돈을 사탕의 가격으로 나누면 매입 가능한 캔디의 최대수량
	//그 나머지가 남은 돈이 된다.
	cout << "최대로 살 수 있는 캔디=" << money/candy<<endl;
	cout << "캔디 구입 후 남은 돈 = " << money % candy << endl;
	return 0;
}