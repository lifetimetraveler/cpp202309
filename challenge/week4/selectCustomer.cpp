#include<iostream>
#include<string>
using namespace std;

int main()
{
	const int maxPeople = 3;//���ο��� 
	//cout << "�� ���� ���� �Է��϶�: ";
	//cin >> maxPeople;
	string names[maxPeople];
	int ages[maxPeople];

	for (int a = 0; a < maxPeople; a++)//�� �ο� �� ��ŭ �Ʒ� �������� �ݺ�
	{
		cout << "�̸��� �Է��ϼ���: ";//�̸� �Է¹ް�, ���� �Է� ����
		cin >> names[a];
		cout << "���̸� �Է��ϼ���: ";
		cin >> ages[a];
	}

	int ageThreshold;//���� �Է¹ޱ� ���� ����
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ��� : ";
	cin >> ageThreshold;//���̸� �Է¹���

	cout << ageThreshold << "�� �̻��� ����:\n";
	int k = 0;
		for (int a = 0; a < maxPeople; a++)//�ο� ����ŭ �Ʒ� ������ �ݺ�
		{
			if (ages[a] > ageThreshold)//�迭�� �ϳ��� ���鼭 �Է��� ���̺��� ������
			{
				cout << names[a]<<" \n";//�� �迭�� �ε��� ���ڰ� ���� �̸��� �����
				k++;//�� if���� ����Ǹ� 1�� �÷��� ����� �� ���غ��� ������ üũ
			}
			
		}
		if (k == 0)//k�� 0�� ���� ���� if���� ������� �ʾ����� ����. ����, �ƹ��� ���ٴ°��� ����
		{
			cout <<ageThreshold<< "�� ���� ���̰� ���� ���� ���� ���� �ʽ��ϴ�.";//�׷� ��쿡 �̰��� ���
		}


	return 0;
}