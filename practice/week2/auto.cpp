#include<iostream>
using namespace std;

auto add(int x, int y)//auto�� ����ؼ� �����Ϸ��� �ڵ����� ��ȯ�� ���� �� �Լ� ����
{
	return x + y;
}

int main()//���� �Լ��� �̿��ؼ� sum�Լ��� �ҷ��ͼ� ���
{
	auto sum = add(5, 6);
	cout << sum;
	return 0;
}