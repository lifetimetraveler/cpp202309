#include<iostream>
#include<string>
using namespace std;

int main()
{//��Ʈ�� �Է��� ���� ����
	string s1, s2;
	int count = 0;//�عְŸ��� �ޱ����� ����
	//���� �Է�
	cout << "DNA1 : ";
	cin >> s1;
	cout << "DNA2 : ";
	cin >> s2;


	if (s1.length() != s2.length())//��Ʈ���� ���̰� �ٸ���
	{
		cout << "����: ���̰� �ٸ�" << endl;//���
	}
	else
	{//�� �迭(��Ʈ��)�� ���̸�ŭ �ݺ�
		for(int i=0;i<s1.length();i++)
		{
			if (s1[i] != s2[i])//��� �迭�� Ȯ�� �ϴٰ� �ٸ���
			{
				count += 1;//ī��Ʈ�� �ø�
			}
			
		}
		cout << "�عְŸ���" << count << endl;//ī��Ʈ�� ���
	}
	return 0;
}