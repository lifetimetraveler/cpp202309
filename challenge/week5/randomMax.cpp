#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	const int numCell = 10;//numCell�� 10���� ���ȭ
	int numList[numCell][numCell];//numCell�� ���ο� ���θ� ���� ������ �迭 ����

	for (int i = 0; i < numCell; i++)//������ �迭�� �������� �Ҵ�
	{
		for (int j = 0; j < numCell; j++)
		{
			numList[i][j] = rand() % 1000;//0~999������ ���� �Ҵ�
		}
	}
	cout << endl;

	int max=0;//ū ���� ���� ���� ����
	int maxI;//i�� �ֱ� ���� ����
	int maxJ;//j�� �ֱ� ���� ����

	for (int i = 0; i < numCell; i++)
	{
		int b = 0;//�迭 ������ ��� ���Ҵ��� Ȯ���� ���� ����, ���� �� i�� ������ ��, 0���� �ʱ�ȭ
		for (int j : numList[i]) {
			b++;
			if (j > max)//max�� ����� ������ ū ���� ������ ����
			{
				max = j;//ū ���� �ٲ���
				maxI = i;//�� ���� i�� ����
				maxJ = b-1;//b�� �ø��� �����ϴϱ� 1�� ����, if �� �ڿ� b++�� �Űܵ� ����
			}
		}

		cout << "���� ū ����" << max << "�̰�,";
		cout << "i�� j�� ����" << maxI << ", " << maxJ << "�Դϴ�" << endl;
		cout << "���� ���: " << numList[maxI][maxJ] << endl;

		return 0;

	}
}