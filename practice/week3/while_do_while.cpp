#include<iostream>

using namespace std;

int main()
{
	int number = 0;
	while (number < 10)//��ȣ ���� ���ǿ� ������ ��� �ݺ�
	{
		number++;//�ݺ� �� ������ 1�� ����
		if (number % 3 == 0)//3���� ������ �������� 0�� ��
			continue;//�ݺ� ���� ó������ ���ư�
		else// �� ���� ��쿡�� ����� ��. number�� ����
			cout << "number �� : " << number << endl;
	}
	return 0;
}