#include<iostream>
#include<time.h>
using namespace std;

int main() {
	srand(time(NULL));

	int answer = rand() % 100;//������ ��, ���� ����
	int tries = 0;

	int guess;//����ڰ� �Է��� ��

	do {
		cout << "������ �����Ͽ� ���ÿ�:";
			cin >> guess; //������� �Է�
		tries++;//�ѹ� �Ҷ����� Ƚ���� 1�� �ö󰡵���

		if (guess > answer)//������ ������ �Ʒ����� ���
			cout << "������ ������ �����ϴ�" << endl;
		if (guess < answer)//�����̳����� �Ʒ����� ���
			cout << "������ ������ �����ϴ�" << endl;
	} while (guess != answer);//����� ������ �������� 0false�� ��������
	cout << "�����մϴ�. �õ� Ƚ��=" << tries << endl;
	return 0;
	
}