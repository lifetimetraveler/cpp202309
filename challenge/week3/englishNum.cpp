#include <iostream>
using namespace std;

int main()
{
	int number;//��������
	cout << "���ڸ� �Է��Ͻÿ�.";
	cin >> number;//�Է� ���� ���� �ʱ�ȭ
	if (number == 0)//number�� 0�̸� true
		cout << "zero\n";//�� ���� �´� ���� ���    \n�� �� �ٲ�
	else if (number == 1)//number�� 1�̸� true
		cout << "one\n";
	else// �� ���� ������ ��� many���
		cout << "many\n";
		return 0;
}