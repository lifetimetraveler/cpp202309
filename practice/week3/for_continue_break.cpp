#include<iostream>

using namespace std;

int main()
{
	int number = 7;

	for (int i = 0; i < 10; i++)
	{
		if (i % 3 == 0)//�������� 0�϶� == 3�� ����� ��
			continue;//�ݺ����� ó������ ���ư�
		else if (i == number)//i�� 7�� �Ǹ� �ݺ������� Ż���ϰ� ��
			break;
		else//3�� ����� �ƴ� ���� i�� ���� ����� ��
			cout << "���� i��: " << i << endl;

	}
	return 0;
}