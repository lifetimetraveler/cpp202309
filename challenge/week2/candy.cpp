#include <iostream>
using namespace std;

int main()
{//������ ���� ��ġ�� �ޱ� ���� ���� ����
	int money;
	int candy;

	//���� ������ �Է� ����
	cout << "������ �ִ� �� = " ;
	cin >> money;
	cout << "ĵ���� ���� = " ;
	cin >> candy;




//���� ������ ���
	cout << "���� ������ �ִ� �� : " << money<<endl;
	cout << "ĵ���� ���� : " << candy<<endl;
	//���� ������ �������� ������ ���� ������ ĵ���� �ִ����
	//�� �������� ���� ���� �ȴ�.
	cout << "�ִ�� �� �� �ִ� ĵ��=" << money/candy<<endl;
	cout << "ĵ�� ���� �� ���� �� = " << money % candy << endl;
	return 0;
}