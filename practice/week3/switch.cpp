#include<iostream>
using namespace std;

int main()
{
	int number = 3;
	switch (number) {
	case 1:
		cout << "number ���� 1�Դϴ�." << endl;
		break;
	case 2:
		cout << "number ���� 2�Դϴ�." << endl;
		break;
	case 3://number �� 3�� ��쿡 �� �Ʒ����� �� ����. �׷��� break���� Ż��
		cout << "number ���� 3�Դϴ�." << endl;
		break;
	default://�Ҵ� ���� ���� ��쿡�� �Ʒ��� ����
		cout << "number ���� �� �� �����ϴ�." << endl;
		break;
	}
	return 0;
}