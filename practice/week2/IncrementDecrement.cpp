#include <iostream>

using namespace std;

int main()
{
	int x = 1;

	cout << "x = " << x++ << endl;//1출력 후 2됨
	cout << "x = " << x++ << endl;//2출력후 3이됨
	cout << "x = " << ++x << endl;//3에서바로 4가 된후 출력
	cout << "x = " << x-- << endl;//4출력후 -1
	cout << "x = " << x-- << endl;//3출력후 -1
	cout << "x = " << --x << endl;//바로 -1 하여 1이 되어 바로 출력

	return 0;
}