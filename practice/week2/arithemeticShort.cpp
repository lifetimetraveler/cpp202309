#include<iostream>

using namespace std;

int main()
{
	int two = 2;//�װ��� ���� ���� �� �ʱ�ȭ
	int eight = 8;
	int sum1 = 2;
	int sum2 = 2;

	sum1 = sum1 + two;
	sum2 += eight;//��Ģ������ ����ؼ� sum2�� eight�� ���ϴ� ����
	cout << "sum1 = " << sum1 << endl;//����� ���
	cout << "sum2 = " << sum2 << endl;
	return 0;
}