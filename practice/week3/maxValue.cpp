#include<iostream>
using namespace std;

int main()
{
	int a, b, c, largest;//4 ���� ���� ����
	
	cout << "3 ���� ������ �Է��Ͻʽÿ�: ";
	cin >> a >> b >> c;//3 ���� ���� ����

	if (a > b && a > c)//a�� b�� c���� ũ�� 1 �� ���� ������ 1
		largest = a;
	else if (b > a && b > c)//b�� a�� c���� ũ�� 1, �� �����ؾ� 1
		largest = b;
	else//�� ���� ���. c�� ���� ũ�� 1 
		largest = c;
	//�� ���� ������ largest�� �� ������ �ʱ�ȭ
	cout << "���� ū ������" << largest << endl;
	return 0;
}