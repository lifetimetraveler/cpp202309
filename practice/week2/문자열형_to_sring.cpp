#include <iostream>
#include<string>
using namespace std;

int main()
{
	string s1 = "���";
	string s2;
	s2 = s1 + " " + to_string(10) + "��";//to_string�� ���� ������ 10�̶�� ���� int���̿��� ������ �߻�.
	//s2=s1+""+10+"��"  to_string�� �ٸ� �ڷ����� string�� ���ս����ش�.
		cout << s2 << endl;
	return 0;
}