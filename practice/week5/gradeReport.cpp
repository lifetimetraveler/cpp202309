#include<iostream>
#include<string>
using namespace std;

int main()
{
	const int STUDENT = 5;//�л����� ����� ����
	const int SUBJECT = 3;//���� ���� ����� ����
	int scores[STUDENT][SUBJECT];//�л��Ʒ��� ������ ���� 2�� �迭 ����, ���⿡ ������ ����
	string studentNames[STUDENT]//�л� �� ��ŭ �迭 ����,�л��� �̸� ����,�ʱ�ȭ
		= { "����", "����", "ö��", "�̹�", "����" };
	string subjectNames[SUBJECT] =//���� �� ��ŭ �迭 ����,������ �̸�, �ʱ�ȭ
	{ "����","����","cpp" };

	for (int i = 0; i < STUDENT; i++)//�л� �� ��ŭ �Ʒ� ���ù� �ݺ�
	{
		cout << studentNames[i]//���� �л��̸��� �������ְ� ������ ���
			<< "�� ������ �ϳ��� �Է��ϼ���." << endl;
		for (int j = 0; j < SUBJECT; j++)//�� �л��� �̸��� ������ ���� ����ŭ �ݺ�
		{
			cout << subjectNames[j] << ":";//���� �̸� ����
			cin >> scores[i][j];//���� �´� ���� �Է� ����
		}
	}

	for (int i = 0; i < STUDENT; i++)//�л� �� ��ŭ �Ʒ� �ݺ�
	{
		cout << studentNames[i] << "�� ��� ������";//�� �迭�� �´� �л� ���
		double sum = 0;
		double average = 0;
		for (int j = 0; j < SUBJECT; j++)// �� �л��� ���� ���� ������ �ҷ��ͼ� ����� ��
		{
			sum += scores[i][j];
		}
		average = sum / SUBJECT;//�̷��� ���Ӱ� �ʱ�ȭ�� sum�� ���� average�� �Ҵ�
		cout << average << "�Դϴ�." << endl;//�ʱ�ȭ�� average�� ���� ���
	}
	return 0;
}