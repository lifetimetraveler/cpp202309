#include<iostream>
#include<string>
using namespace std;
//�� ���� �Լ��� ����
string toLowerStr(string str);
string toUpperStr(string str);
int clacHammingDist(string s1, string s2);

int main()
{
	string s1, s2;//���� �Է� �ޱ� ���� ��Ʈ�� ����
	int count = 0;
	//���� �Է� ����
	cout << "DNA1 : ";
	cin >> s1;
	cout << "DNA2 : ";
	cin >> s2;

	
	if (s1.length() != s2.length())//���� ���̰� �ٸ� ���
	{
		cout << "����: ���̰� �ٸ�" << endl;
	}
	else// �� ���� ���
	{
		int count = clacHammingDist(s1, s2);
		cout << "�عְŸ���" << count << endl;
	}
	return 0;
}

string toLowerStr(string str)
{
	string cop = str;//str�� ���� ������ ���� �� �ʱ�ȭ
	for (char& a : cop)//cop�� ���� ��� ��Ʈ���� Ȯ��
	{
		a = tolower(a);//�� �ε����� �� ���ڸ� �ҹ��ڷ� ����
	}
	return cop;//�̷��� ��ȯ�� cop�� ���
}
//���� ��������
string toUpperStr(string str)
{
	string cop = str;
	for (char& a : cop)
	{
		a = toupper(a);
	}
	return cop;
}

int clacHammingDist(string s1, string s2)
{
	int count=0;
	string a=toLowerStr(s1);//a�� b�� �Ѵ� �ҹ��ڷ� ���� ��Ʈ���� �� ������ ����
	string b=toLowerStr(s2);
	for (int i = 0; i < s1.length(); i++)// �� ��Ʈ���� ���̸�ŭ �ݺ�
	{
		if (a[i] != b[i])//�� �ε����� �ٸ��� ����
		{
			count += 1;
		}
	}
	return count;//�� Ƚ���� �ݺ�
}