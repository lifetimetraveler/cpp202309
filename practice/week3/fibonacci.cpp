#include<iostream>
using namespace std;

int main()
{
	int p = 0;//���� ���� ���� �� �ʱ�ȭ
	int n = 0;
	int t = 0;

	for (int i = 1; i < 10; i++)//1~9���� �ݺ�
	{
		p = 0;//�ݺ��� �� ������ �� ������ ���� 0�� 1�� �ʱ�ȭ.
		n = 1;

		for (int j = 1; j <= i; j++)//���� for ���� �� �� �����ϸ� �� for���� 1~i�� �� ���� �ݺ�
		{
			cout << n << ", ";//

			t = n; //n�� �׻� 1�� �ٽ� �Ѵܰ� ���� for���� �ݺ��ϸ鼭 �ʱ�ȭ �Ǿ t�� 1���� ����
			n += p;//n�� p�� �������� n�� �ʱ�ȭ
			p = t;
		}
		cout << endl;
	}
	return 0;
}