#include<iostream>
using namespace std;

const int NUM_USERS = 3;
const int NUM_ITEMS = 3;
int userPrefuerneces[NUM_USERS][NUM_ITEMS];
//����� ��ȣ���� �Է� �޴� �Լ�
void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS])
{
	for (int i = 0; i < NUM_USERS; ++i)//���� ����ŭ �ݺ�
	{
		cout << "�����" << (i + 1) << "�� ��ȣ���� �Է��ϼ��� (" << NUM_ITEMS << "���� �׸� ����): ";
		for (int j = 0; j < NUM_ITEMS; ++j)
		{
			cin >> preferences[i][j];
		}
	}
}
//����� �� ��õ �׸��� ã�� ����ϴ� �Լ�
void findRecommendeditems(const int preferences[NUM_USERS][NUM_ITEMS])
{
	for (int i = 0; i < NUM_USERS; ++i)
	{
		int maxPreferenceindex = 0;
		for (int j = 1; j < NUM_ITEMS; ++j)//�׸��� ��-1 ��ŭ �ݺ�, ���� ó���� �ƽ������۷����� 0�̿��� �ѹ� �����ص� ��.
		{
			if (preferences[i][j] > preferences[i][maxPreferenceindex])//��ȣ���� �� ���� ���� ������
			{
				maxPreferenceindex = j;//�� ������� �׶��� �ε��� ���� ����
			}
		}
		// ������� ��ȣ �׸��� ���
		cout << "����� " << (i + 1) << "���� ��õ�ϴ� �׸�: ";
		cout << (maxPreferenceindex + 1) << endl;
	}
}
int main() {
	initializePreferences(userPrefuerneces);//�� �Լ��� ���� ������ ������ userPreference�� ����
	findRecommendeditems(userPrefuerneces);

	return 0;
}