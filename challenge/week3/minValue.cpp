#include<iostream>
using namespace std;

int main()
{
	int a, b, c, smallest;//4 ���� ���� ����

	cout << "3 ���� ������ �Է��Ͻʽÿ�: ";
	cin >> a >> b >> c;//3 ���� ���� ����

	if (a < b && a < c)//a�� b�� c���� ������ 1 �� ���� ������ 1
		smallest = a;
	else if (b < a && b < c)//b�� a�� c���� ������ 1, �� �����ؾ� 1
		smallest = b;
	else//�� ���� ���. c�� ���� ������ 1 
		smallest = c;
	//�� ���� ������ smallest�� �� ������ �ʱ�ȭ
	cout << "���� ���� ������" << smallest << endl;//��� �� ���
	return 0;
}