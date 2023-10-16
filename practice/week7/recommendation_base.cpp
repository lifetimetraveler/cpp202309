#include <iostream>
using namespace std;

int main() {
	const int NUM_USERS = 3;
	const int NUM_ITEMS = 3;
	int userPreferences[NUM_USERS][NUM_ITEMS];

	//�� ����ڸ� ����ϰ� �Է� ���� ������ ���
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "����� " << (i + 1) << "�� ��ȣ���� �Է��ϼ��� (";
		cout << NUM_ITEMS << "���� �׸� ���� ):";
	for (int j = 0; j < NUM_ITEMS; ++j)
		{
			cin >> userPreferences[i][j];
		}
	}

	//����� ��õ �׸� ����
	for (int i = 0; i < NUM_USERS; ++i) {//����� ����ŭ �ݺ� �� �ִ뼱ȣ �׸��� ���� ����
		int maxPreferenceIndex = 0;
		for (int j = 1; j < NUM_ITEMS; ++j)//�׸��� ��-1 ��ŭ �ݺ�, ���� ó���� �ƽ������۷����� 0�̿��� �ѹ� �����ص� ��.
		{
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex])//��ȣ���� �� ���� ���� ������
			{
				maxPreferenceIndex = j;//�� ������� �׶��� �ε��� ���� ����
			}
		}


		// ������� ��ȣ �׸��� ���
		cout << "����� " << (i + 1) << "���� ��õ�ϴ� �׸�: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}
	return 0;
}