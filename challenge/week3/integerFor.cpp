#include<iostream>

using namespace std;

int main()
{
	int userinput;


	
	
	for (int i = 0; i < 10; i++) {//1~09���� �ݺ�
		cin >> userinput;//������ �Է�
		if (userinput == 0)//0�� �ԷµǸ� Ż��
			break;
		cout << "�Է°�: " << userinput << "Ƚ��: " << i << endl;//��� ���
		
	}//�� ������ �ݺ��Ǽ� 10�� �ݺ�
	cout << "���� �Ǿ����ϴ�.";
	return 0;

}