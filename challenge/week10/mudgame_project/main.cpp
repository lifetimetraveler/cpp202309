#include <iostream>
#include <string>
#include "user.h"
using namespace std;
//���� ũ�⸦ ����� ����
const int mapX = 5;
const int mapY = 5;

// ����� ���� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void opti(int& user_x, int mapX, int& user_y, int mapY);
//�߰� ���

//��ü�� �����ڸ� ����Ͽ��� ��ü�� ������ �� �Լ����� ���� �ٲ�.
void checkState(int map[][mapX], int user_x, int user_y,User& user);//������ ���� ������ ���� ������ ���� �Լ�. ������ ��ġ Ȯ�� �� hp ��ȯ

// ����  �Լ�
int main() {

	//������� ü���� ���� Ŭ���� ����� 20���� ü�� ����
	User my_user;
	my_user.hp = 20;

	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},//�迭�� ���� ������Ʈ���� �Ҵ�
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };

	


	// ������ ��ġ�� ������ ����
	int user_x = 0; // ���� ��ȣ
	int user_y = 0; // ���� ��ȣ

	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����
		
		//Hp�� 0�̸� ���Ḧ ����
		if (my_user.GetHP() == 0)//0�� ���. ��ü �Լ� ȣ��
		{
			cout << "Hp�� 0�� �Ǿ����ϴ�." << endl << "������ �����մϴ�.";
			break;
		}
		// ������� �Է��� ������ ����
		string user_input = "";
		cout << "���� HP: " << my_user.GetHP();//��ü �Լ�  ȣ��
		cout << "��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;

		if (user_input == "��") {//�Է� ���� ���� ���� ���
			// ���� �� ĭ �ö󰡱�
			user_y -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);//�̵��� ���� Ÿ�������� Ȯ���ϴ� �Լ�. �߸��Ǹ� flase�� ���. inMap�� �� ���� �ޱ� ���� ����
			if (inMap == false) {//���� �Լ��� false�� ����� ���
				opti(user_x, mapX, user_y, mapY);
			}
			else {//�Է� ���� �̵� ���� Ÿ���� ���
				cout << "���� �� ĭ �ö󰩴ϴ�." << endl;//�޼����� ���� ����ϴ� �Լ��� ����
				displayMap(map, user_x, user_y);
				my_user.DecreaseHP(1);//�̵��� ��ȿ�Ͽ� �̵� ������ ��ü �Լ��� ȣ���Ͽ� HP�� ���ҽ�Ŵ  
				checkState(map, user_x, user_y,my_user);//��, ���� ���� ������ �� ������ �޼����� ���� �Լ�
			}
		}
		else if (user_input == "��") {//��� ������ ����. x�� y�� ���� �׿� �°� ����
			// TODO: �Ʒ��� �� ĭ ��������
			user_y += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				opti(user_x, mapX, user_y, mapY);
			}
			else {
				cout << "�Ʒ��η� �� ĭ �������ϴ�." << endl;
				displayMap(map, user_x, user_y);
				my_user.DecreaseHP(1);//��ü �Լ��� ü�� 1�� ����
				checkState(map, user_x, user_y, my_user);
			}
		}
		else if (user_input == "��") {//��� ������ ����. x�� y�� ���� �׿� �°� ����
			// TODO: �������� �̵��ϱ�
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);

			if (inMap == false) {
				opti(user_x, mapX, user_y, mapY);
			}
			else {
				cout << "�������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
				my_user.DecreaseHP(1);//��ü �Լ��� ü�� 1�� ����
				checkState(map, user_x, user_y,my_user);
			}
		}
		else if (user_input == "��") {//��� ������ ����. x�� y�� ���� �׿� �°� ����
			// TODO: ���������� �̵��ϱ�
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				opti(user_x, mapX, user_y, mapY);
			}
			else {
				cout << "���������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
				my_user.DecreaseHP(1);//��ü �Լ��� ü�� 1�� ����
				checkState(map, user_x, user_y,my_user);
			}
		}
		else if (user_input == "����") {//������ �Է� ���� ���
			// TODO: ���� �����ֱ� �Լ� ȣ��
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "����") {//���Ḧ �Է��� ���
			cout << "�����մϴ�.";
			break;//break�� ���� ������ Ż��
		}
		else {//���� ��찡 �ƴ� �ٸ� ���� �Է��Ѱ��
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;//�ٽ� ���� ���ư�
		}

		// �������� �����ߴ��� üũ
		bool finish = checkGoal(map, user_x, user_y);//������ �������� �����ϸ� true�� ��ȯ�ϴ� �Լ��� �� ���� �ޱ� ���� ����
		if (finish == true) {//������ Ʈ�簡 �Ҵ�Ȱ�� ��, �������� ��ǥ�� ���� ��ǲ��ǥ�� ������ ��.
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;//���� �޼��� ��°� ���� ���� ����
			cout << "������ �����մϴ�." << endl;
			break;
		}

	}
	return 0;
}


// ������ ����� ��ġ ����ϴ� �Լ�
void displayMap(int map[][mapX], int user_x, int user_y) {//�迭�� �Է� ��ǥ�� �Ű������� ����
	for (int i = 0; i < mapY; i++) {//���� ���θ�ŭ �ݺ�
		for (int j = 0; j < mapX; j++) {//���� �� ���ο��� ���θ�ŭ �ݺ�
			//�� �迭�� Ž���ϵ� �� �迭�� ������ ���� ������ ������ ���, �� �迭�� ������ �������� ������ ���� ��ġ�� ������Ʈ�� ���
			//�� �޼����� ����� �� ���θ� ������ ĭ�� ���
			if (i == user_y && j == user_x) {//�� �ݺ� �ñ� �� ��ǥ�� �Է���ǥ�� ������
				cout << " USER |"; // �� �� 1ĭ ���� //������ ���
			}
			else {//���� �������� �ʴ� ĭ�� �ݺ��� �����ϰ� ���� ��
				int posState = map[i][j];//�̶��� ������ �迭�� �ش��ϴ� ��(������, �� ��)�� ������ �޾ƿ�
				switch (posState) {
				case 0://�� ������ ���
					cout << "      |"; // 6ĭ ����
					break;
				case 1://�������� ���
					cout << "������|";
					break;
				case 2://���� ���
					cout << "  ��  |"; // �� �� 2ĭ ����
					break;
				case 3://������ ���
					cout << " ���� |"; // �� �� 1ĭ ����
					break;
				case 4://�������� ���
					cout << "������|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;//������ �ݺ����� ������ �� 1ȸ ������ ������ ����Ͽ��� ���ΰ��� ��谡 ��
	}
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;//��ȯ���� ���� ������ ����
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {//�Է� ��ǥ�� 0�̻��̿��� �ϰ� ���� ũ�⺸�� ���� ���
		checkFlag = true;//Ʈ�縦 �Ҵ��Ͽ� ��ȿ�� ��ǥ���� ���
	}
	return checkFlag;// ���� �� ���
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool checkGoal(int map[][mapX], int user_x, int user_y) {// �Է� ��ǥ���� �迭�� �Ű�������
	// ������ �����ϸ�
	if (map[user_y][user_x] == 4) {//�Է� ��ǥ�� ���� �� �迭�� �������� ������
		return true;//Ʈ�縦 ���
	}
	return false;//if �� ������� ���� �������� �ƴϸ� false�� ���
}

void checkState(int map[][mapX], int user_x, int user_y,User& user)
{
	int posState = map[user_y][user_x];//�� �迭 �ε����� �ִ� ���� ���� ������ ���� �� �� �迭�� ������ �ʱ�ȭ
	switch (posState)//��, �� �迭�� � ���� ����ִ��� Ȯ���ϰ� �׿����� ������ ��.
	{
	case 0://������ ���, �ƹ��͵� ���� ����
		break;
	case 1://�������� ���
		cout << "�������� �������ϴ�.\n";//�������� �����ٴ� �Լ� ���
		break;
	case 2://���� ���� ���
		cout << "���� �������ϴ�. Hp�� 2 �پ��ϴ�.\n";//�޼��� ���
	    user.DecreaseHP(2);//�������� ��//��ü �Լ��� ü�� 2�� ����
		break;
	case 3://������ �������
		cout << "������ ȹ���߽��ϴ�. Hp�� 2 �þ�ϴ�.\n";//�޼����� ����ϰ� ȸ������
		user.hp += 2;//��ü�� public ������ �����Ͽ� 2�� ����
	case 4://�������� ��� �ƹ��͵� ���� ����
		break;
	}
}

//���� �޼��� ��� �� �̵� ���
void opti(int& user_x, int mapX, int& user_y, int mapY) 
{//�� �ٱ����� ������ �� ������ ��Ȳ�� �´� ��ǥ ���� ����
	cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;//���� �޼����� ����ϱ� ����
	if (user_x >= mapX)//�ʺ��� ��ǥ�� Ŀ����
	{
		user_x -= 1;
	}
	else if (user_x < 0)//���� �ٱ����� ������
	{
		user_x += 1;
	}
	else if (user_y >= mapY)//�ʺ��� ��ǥ�� Ŀ����
	{
		user_y -= 1;
	}
	else if (user_y < 0)//��ǥ�� �ٱ����� ������
	{
		user_y += 1;
	}
}