#include<iostream>
#include<string>
#include<vector>//���͸� ����ϱ� ���� 
using namespace std;

int main()
{
	int maxPeople = 0;//���ο��� 
	cout << "�� ���� ���� �Է��϶�: ";
	cin >> maxPeople;

	//�̸��� ���̸� ���� ���͸� ����
	vector<string>names;
	vector<int>ages;

	//���Ϳ� ���� ���� ���� ��Ʈ���� ��Ʈ�� ���� ����
	string name;
	int age;

	//push_back��������� �ʰ� �ٷ� names[a]�� ���� �����Ͽ����� ���� ���Ͷ� ����.

	for (int a = 0; a < maxPeople; a++)//�� �ο� �� ��ŭ �Ʒ� �������� �ݺ�
	{
		cout << "�̸��� �Է��ϼ���: ";//�̸� �Է¹ް�, ���� �Է� ����
		cin >> name;                   //�Է¹��� ������ ���Ϳ� �־��ش�.
			names.push_back(name);
		cout << "���̸� �Է��ϼ���: ";
		cin >> age;
		ages.push_back(age);
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