#include<iostream>
using namespace std;

int main()
{
	//ȭ�� �µ��� �ޱ� ���� ����. �Ҽ��� ����� ���Ͽ� double ���
	double fire;

	//ȭ�� �µ��� �Է¹ޱ� ���� ����
	cout << "ȭ���µ� = ";
	cin >> fire;
	
	//ȭ���µ��� ����ϰ� �����µ��� ����Ͽ� ����Ѵ�.
	cout << "ȭ���µ�:" << fire<<endl;
	cout << "�����µ� = " << (5.0 / 9.0) * (fire - 32) << endl;
	return 0;
}