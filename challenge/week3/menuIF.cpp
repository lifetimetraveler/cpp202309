#include <iostream>
using namespace std;

int main()
{
	int choice;//if���� �� ���� ����
	//�Ʒ��� ���� ������ ȭ�� ���
	cout << "1. ���� ����" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	cin >> choice;//choice�� ���� �Է�

	if (choice == 1)//�Էµ� ���� ��ȣ �Ȱ� ������ true
		cout << "���� ������ �����߽��ϴ�." << endl;
	else if (choice == 2)//�Էµ� ���� ��ȣ �Ȱ� ������ true
		cout << "���� �ݱ⸦ �����߽��ϴ�." << endl;
	else if (choice == 3)//�Էµ� ���� ��ȣ �Ȱ� ������ true
		cout << "���α׷��� �����մϴ�." << endl;
	else//choice�� �� ���� ������ ����� ��
		cout << "�߸��� �����Դϴ�." << endl;
	return 0;//break �ʿ� ����
}