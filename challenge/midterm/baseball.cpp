#include <iostream>
#include <string>
using namespace std;


//�ߺ��Ǵ� ���ڸ� Ȯ���ϱ� ���� �Լ� ����
bool checkNumber(int userNumber);

int main() {
	int randomNum; // ����� �ϴ� 3�ڸ����� ���� ���� ����
	char firstNum; // ������ ù��° �ڸ���
	char secondNum; // ������ �ι�° �ڸ���
	char thirdNum; // ������ ����° �ڸ���

	while (1) {
		randomNum = rand() % 900 + 100; // ������ 3�ڸ��� ����

		bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����

		// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�

		string num = to_string(randomNum);//������ ���� string�� �ִ´�.
		firstNum = num[0];//string �迭�� �� ���ڰ� char���� ������ ����. �� �ڸ����� �Ҵ��ϴ� ����
		secondNum = num[1];
		thirdNum = num[2];

		//�Լ��� ����Ͽ� �ߺ��Ǵ��� Ȯ��
		same = checkNumber(randomNum);//�ߺ����ٸ� �Լ��� true�� ����. ������ false����.

		if(same==false)//�ߺ��� �ִ� ���. ���� ���� ����.
		{
			continue;
		}
		if (same == true) {//�ߺ��� ������ Ż��
			break;
		}

	}

	int turn = 0;//�ݺ� Ƚ���� Ȯ���ϱ� ���� ���� ���� �� �ʱ�ȭ
	while (1)
	{
		//�õ� Ƚ���� ���
		cout << turn + 1 << "��° �õ��Դϴ�. " << endl;

		int userNumber; // ����ڰ� �Է��� ���ڸ��� ���� ����
		char guessFirst; // ������ ������ ù��° �ڸ���
		char guessSecond; // ������ ������ �ι�° �ڸ���
		char guessThird; // ������ ������ ����° �ڸ���


		// ����ڿ��� ���ڸ� ���� �Է¹޴� �ڵ� ���
		while (1) {
			cout << "���ڸ� ���� �Է����ּ���: ";
			cin >> userNumber;

			bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����
			// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�

			//�� �ڸ� ���� �����ϱ� ���� string�� ����
			string check = to_string(userNumber);

			//check string�� ���̰� 3�� �ƴϸ�(3 �ڸ����� �ƴϸ�) ������ ����
			if (check.length() != 3) {
				cout << "�Էµ� ���ڰ� 3�ڸ� ���� �ƴմϴ�. �ٽ� �Է��ϼ���." << endl;
				continue;
			}

			//�� �ڸ����� string���� char�� ����
			guessFirst = check[0];
			guessSecond = check[1];
			guessThird = check[2];

			//�Լ��� ����Ͽ� �ߺ��Ǵ��� Ȯ��
			same = checkNumber(userNumber);//�ߺ����ٸ� �Լ��� true�� ����. ������ false����.



			if (same == false)//�ߺ��� �ִ� ���. ���� �޼��� ���
			{
				cout << "�Է��� ���ڿ� �ߺ��� ���ڰ� �ֽ��ϴ�. �ٽ� �Է��ϼ���." << endl;
			}
			//�ߺ��� ���ٸ� Ż��
			if (same == true) {
				break;
			}
		}


		int strike = 0; // ��Ʈ����ũ ������ �����ϴ� ����
		int ball = 0; // �� ������ �����ϴ� ����

		// TODO 2: ����� ������ ������ �ڸ����� ���ڸ� ���ϸ� ��Ʈ�� �ֱ� ���� �ڵ��� �ۼ�
		
		
		//�Է��� ���� ���� ������ ���� �ڸ����� ���ڰ� �����ϴٸ�
		//strike�� 1 ����.
		if (guessFirst == firstNum)
		{
			strike++;
		}
		if (guessSecond == secondNum)
		{
			strike++;
		}
		if (guessThird == thirdNum)
		{
			strike++;
		}

		//�Է��� ���� ���� ���� ���ڴ� ��ġ�ϳ� �ٸ� �ڸ����� ���
		//ball++
		if (guessFirst == secondNum || guessFirst == thirdNum)
		{
			ball++;
		}
		if (guessSecond == firstNum || guessSecond == thirdNum)
		{
			ball++;
		}
		if (guessThird == firstNum || guessThird == secondNum)
		{
			ball++;
		}


		//��Ʈ�� ���
		cout << userNumber << "�� ��� : " << strike << " ��Ʈ����ũ, " << ball << "�� �Դϴ�." << endl;

		//strike�� 3 ���� ���� ������ ������̱� ������ ���� ���
		if (strike == 3) {
			cout << "������ ������ϴ�. �����մϴ�."<<endl;
			break;
		}
		//���� ���� ���ٸ� �ƿ��� ���
		if (strike + ball == 0)
		{
			cout << "�ƿ��Դϴ�."<<endl;
		}


		turn += 1;//Ƚ���� ����
	}

	return 0;
}

//�Է¹��� ���� �ڸ� ���� �ߺ��Ǵ� �� Ȯ���ϴ� �Լ�
//�ߺ��� �ִٸ� false�� ����ϰ� ���ٸ� true�� ����Ѵ�.
bool checkNumber(int userNumber)
{
	string check = to_string(userNumber);//string �迭�� �����Ͽ� �ڸ����� �ߺ��� Ȯ���Ѵ�.
	if (check[0] == check[1] || check[1] == check[2] || check[0] == check[2])
	{
	
		return false;
	}
	return true;
}