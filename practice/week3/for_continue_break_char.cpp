#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str = "The Jin state was formed in southern Korea";
	char find = 'a';
	int size = str.size();//�ݺ����� ���ǹ��� �־��ֱ� ���ؼ� ��Ʈ���� ũ�⸦ ������ �Ҵ�
	int count = 0;

	for (int i = 0; i < size; i++)//���ڿ��� 0���� �����ؼ� ���ڿ��� ������ �ݺ�Ƚ���� ������ ���ǹ� ����.
	{
		if (str[i] == find)//�ݺ����� ������ ����ŭ �ϴ� ���߿� a�� ���ڰ� ���ڿ��� �� ĭ�� �Ѵ޵Ǿ������� count�� ����
			count++;
	}

	cout << "������ a ������" << count << "�� �Դϴ�." << endl;
	return 0;
}