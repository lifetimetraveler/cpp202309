#include <iostream>

using namespace std;

int main()
{
	int vowe1 =0;
	int consonant = 0;
	cout << "�����ڸ� �Է��ϰ� ctrl+z�� ġ����" << endl;

	char ch;
	
	while (cin>>ch) {//���ڸ� �Է� �ް� �׿� ch�� �Ҵ�, true�� �ִ� ���ҵ� ��.
		switch (ch)
		{//�� ���ĺ��� �������� �����̸� vowe�� ���� �ø��� �����̸� consonant�� 1�� �ø�.
		case 'a':
			vowe1++;
			break;
		case 'b':
			consonant++;
			break;
		case 'c':
			consonant++;
			break;
		case 'd':
			consonant++;
			break;
		case 'e':
			vowe1++;
			break;
		case 'f':
			consonant++;
			break;
		case 'g':
			consonant++;
			break;
		case 'h':
			consonant++;
			break;
		case 'i':
			vowe1++;
			break;
		case 'j':
			consonant++;
			break;
		case 'k':
			consonant++;
			break;
		case 'l':
			consonant++;
			break;
		case 'm':
			consonant++;
			break;
		case 'n':
			consonant++;
			break;
		case 'o':
			vowe1++;
			break;
		case 'p':
			consonant++;
			break;
		case 'q':
			consonant++;
			break;
		case 'r':
			consonant++;
			break;
		case 's':
			consonant++;
			break;
		case 't':
			consonant++;
			break;
		case 'u':
			vowe1++;
			break;
		case 'v':
			consonant++;
			break;
		case 'w':
			vowe1++;
			break;
		case 'x':
			consonant++;
			break;
		case 'y':
			vowe1++;
			break;
		case 'z':
			consonant++;
			break;

		}
	}
	cout << "����: " << vowe1 << endl;//��Ʈ����Ʈ�ϸ� Ż���ϰ� 
	cout << "����: " << consonant << endl;//��� ���
	return 0;
}