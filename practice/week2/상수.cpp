#include<iostream>
#define PI 3.14159265359
using namespace std;

int main()
{
	int income = 1000;//������ ���ͷ� ������� ���� �� �Ѿ�� �ֹ�
	const double TAX_RATE = 0.25;//��� ó���Ͽ��� ������ ����
	income = income - TAX_RATE * income;//����� �ƴ� income�� ��ȭ

	double x = 100;//���������� PI�� ������� ������ �ʰ� x�� ��ȭ
	x = x * PI;

	cout << x << endl;
	return 0;
}