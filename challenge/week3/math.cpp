#include<iostream>
#include<time.h>
using namespace std;

int main()
{
	int i;
	int ans;
	cout << "��� ������ �ڵ����� �����մϴ�." << endl;

	while (true) {
		int firstNum = rand() % 100;//�������� �� �� ����
		int secondNum = rand() % 100;

		cout << firstNum << "+" << secondNum << "=";//������ �μ� ���
		cin >> ans;
		if (firstNum + secondNum == ans) {//���� ���� ���� ���
			cout << "�¾ҽ��ϴ�." << endl;//�¾ҽ��ϴ� ����� Ż��
			break;
		}
		else {
			cout << "Ʋ�Ƚ��ϴ�." << endl;//�� �������� Ʋ�� ��쿡�� �ٽ� while���� �ݺ�
		}
	}
	return 0;
}