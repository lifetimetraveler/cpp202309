#include<iostream>
using namespace std;

int main() {
	int data[5] = { 5, 19,76,3,10 };
	for (int i = 0; i < 5; i++)//0~4���� �������� �ݺ�. 
	{
		if (data[i] % 2 == 0)//2�� ������ ������ ���� �Ʒ��� ¦���Դϴٰ� ���
			cout << i << ":" << data[i] << "�� ¦���Դϴ�." << endl;
		else//�� ���� ����� Ȧ���� �� �Ʒ� ���� ���.
			cout << i << ":" << data[i] << "�� Ȧ���Դϴ�." << endl;
	}
	return 0;
}