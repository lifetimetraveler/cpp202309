#include <iostream>

using namespace std;

int main()
{
	int x = 1;

	cout << "x = " << x++ << endl;//1��� �� 2��
	cout << "x = " << x++ << endl;//2����� 3�̵�
	cout << "x = " << ++x << endl;//3�����ٷ� 4�� ���� ���
	cout << "x = " << x-- << endl;//4����� -1
	cout << "x = " << x-- << endl;//3����� -1
	cout << "x = " << --x << endl;//�ٷ� -1 �Ͽ� 1�� �Ǿ� �ٷ� ���

	return 0;
}