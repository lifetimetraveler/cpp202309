#include <iostream>
#include<string>
using namespace std;

int main()
{
	string s1 = "Good";//s1, s2���� ����� ���ÿ� �ʱ�ȭ
	string s2 = "Bad";
	bool b = (s1 == s2);//s1�� s2�� �ٸ��� ������ false�� �Ҵ�
	cout << b << endl;//false���� 0���

	s2 = "Good";//s2�� good �� �Ҵ��ؼ� s1�� ������
	b = (s1 == s2);//s1�� s2�� �������� true�� �Ҵ�ȴ�. 
	cout << b << endl;//true ���� 1���
	return 0;
}