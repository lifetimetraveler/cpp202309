#include <iostream>
using namespace std;

int main()
{
	int choice;//switch�� �� ���� ����
	//�Ʒ��� ���� ������ ȭ�� ���
	cout << "1. ���� ����" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	cin >> choice;//switch �� �� ���� �Է�=�޴� ����

	switch (choice)//choice ���� case���� ���� ������ �� �Ʒ� ���� ����
	{//�����ϴٰ� break�� ������ switch Ż��
	case 1:
		cout << "���� ������ �����߽��ϴ�." << endl;
		break;
	case 2:
		cout << "���� �ݱ⸦ �����߽��ϴ�." << endl;
		break;
	case 3:
		cout << "���α׷��� �����մϴ�." << endl;
		break;
	case 4:
		cout << "�߸��� �����Դϴ�." << endl;
		break;
	}
	return 0;
}