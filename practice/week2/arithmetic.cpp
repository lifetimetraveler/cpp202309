#include<iostream>
using namespace std;

int main()
{
	int one = 1;//4개의 변수 선언과 초기화
	int two = 2;
	int three = 3;
	int four = 4;

	cout << "1 + 3 = " << one + three << endl;//그에 맞는 사칙연산값 출력
	cout << "4 - 2 = " <<four - two << endl;
	cout << "2 * 3 = " << two*three << endl;
	cout << "4 / 2 = " << four/two << endl;

	cout << "2 + 3 * 4 = " << two+three*four << endl;
	cout << "2 + 3 * 4 = " << two+three*four<< endl;
	cout << "1 + 4 / 2 = " << one + four/two << endl;
	return 0;
}