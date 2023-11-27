#include <iostream>
#include <string>
#include "user.h"
using namespace std;
//���� ũ�⸦ ����� ����
const int mapX = 5;
const int mapY = 5;

// ����� ���� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y, int user2_x,int user2_y);
bool checkGoal(int map[][mapX], int user_x, int user_y,int user2_x,int user2_y);
void opti(int& user_x, int mapX, int& user_y, int mapY);
bool CheckUser(User user);//������ ä�� Ȯ���� ���� �Լ�.
//�߰� ���

//��ü�� �����ڸ� ����Ͽ��� ��ü�� ������ �� �Լ����� ���� �ٲ�.
void checkState(int map[][mapX], User& user);//������ ���� ������ ���� ������ ���� �Լ�. ������ ��ġ Ȯ�� �� hp ��ȯ
	int current_hp;//�� ���ʿ� �´� ������� ü���� �����ϱ� ����
// ����  �Լ�
int main() {

	Magician m(20);//���ڵ带 ü�� 20���� ����
	Warrior w(20);//����� ü�� 20���� ����
	
	int turn = 0;//���ʸ� Ȯ���ϱ� ����

	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},//�迭�� ���� ������Ʈ���� �Ҵ�
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };

	


	
	
	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����
		//���ʸ� Ȯ��//�� ������ ������ Hp�� ���ʶ�� ������ ���.
		if (turn % 2 == 0)
		{
			cout << "Magician�� �����Դϴ�." << endl;
			current_hp = m.GetHP();
		}
		else if(turn % 2 == 1)
		{
			cout << "Warrior�� �����Դϴ�." << endl;
			current_hp = w.GetHP();
		}

		//Hp�� 0�̸� ���Ḧ ����
		if (CheckUser(current_hp) == false)//CheckUser()�� false ��, hp�� 0�����ΰ��
		{
			cout << "Hp�� 0�� �Ǿ����ϴ�. ȥ�� ���� ������ ������ ���߽��ϴ�." << endl << "������ �����մϴ�.";
			break;
		}
		// ������� �Է��� ������ ����
		string user_input = "";
		cout << "���� HP: " << current_hp;//���� ������ ����� hp ǥ��
		cout << "��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;

		if (user_input == "��") {//�Է� ���� ���� ���� ���
			if (turn % 2 == 0)//�������� ����
			{
				m.user_y -= 1;// ���� �� ĭ �ö󰡱�
				bool inMap = checkXY(m.user_x, mapX, m.user_y, mapY);//�̵��� ���� Ÿ�������� Ȯ���ϴ� �Լ�. �߸��Ǹ� flase�� ���. inMap�� �� ���� �ޱ� ���� ����
				if (inMap == false) {//���� �Լ��� false�� ����� ���
					opti(m.user_x, mapX, m.user_y, mapY);
					continue;
				}
				else {//�Է� ���� �̵� ���� Ÿ���� ���
					cout << "���� �� ĭ �ö󰩴ϴ�." << endl;//�޼����� ���� ����ϴ� �Լ��� ����
					displayMap(map, m.user_x, m.user_y, w.user_x, w.user_y);//���� ǥ��
					m.DecreaseHP(1);//�̵��� ��ȿ�Ͽ� �̵� ������ ��ü �Լ��� ȣ���Ͽ� HP�� ���ҽ�Ŵ  
					checkState(map,  m);//��, ���� ���� ������ �� ������ �޼����� ���� �Լ�
					if (m.wound)//���� �������
					{
						m.doAttack();
						m.wound = 0;
					}
				}
			}
			else if(turn % 2 == 1)//�������� ����
			{
				// ���� �� ĭ �ö󰡱�
				w.user_y -= 1;
				bool inMap = checkXY(w.user_x, mapX, w.user_y, mapY);//�̵��� ���� Ÿ�������� Ȯ���ϴ� �Լ�. �߸��Ǹ� flase�� ���. inMap�� �� ���� �ޱ� ���� ����
				if (inMap == false) {//���� �Լ��� false�� ����� ���
					opti(w.user_x, mapX, w.user_y, mapY);
					continue;
				}
				else {//�Է� ���� �̵� ���� Ÿ���� ���
					cout << "���� �� ĭ �ö󰩴ϴ�." << endl;//�޼����� ���� ����ϴ� �Լ��� ����
					displayMap(map, m.user_x, m.user_y, w.user_x, w.user_y);//�� ǥ��
					w.DecreaseHP(1);//�̵��� ��ȿ�Ͽ� �̵� ������ ��ü �Լ��� ȣ���Ͽ� HP�� ���ҽ�Ŵ  
					checkState(map,  w);//��, ���� ���� ������ �� ������ �޼����� ���� �Լ�
					if (w.wound)//���� �������
					{
						w.doAttack();
						w.wound = 0;
					}
				}
			}
			
		}
		else if (user_input == "��") {//��� ������ ����. x�� y�� ���� �׿� �°� ����
			// TODO: �Ʒ��� �� ĭ ��������
			
			if (turn % 2 == 0)//�������� ����
			{
				m.user_y += 1;// ���� �� ĭ �ö󰡱�
				bool inMap = checkXY(m.user_x, mapX, m.user_y, mapY);//�̵��� ���� Ÿ�������� Ȯ���ϴ� �Լ�. �߸��Ǹ� flase�� ���. inMap�� �� ���� �ޱ� ���� ����
				if (inMap == false) {//���� �Լ��� false�� ����� ���
					opti(m.user_x, mapX, m.user_y, mapY);
					continue;
				}
				else {//�Է� ���� �̵� ���� Ÿ���� ���
					cout << "���� �� ĭ �ö󰩴ϴ�." << endl;//�޼����� ���� ����ϴ� �Լ��� ����
					displayMap(map, m.user_x, m.user_y, w.user_x, w.user_y);//�� ǥ��
					m.DecreaseHP(1);//�̵��� ��ȿ�Ͽ� �̵� ������ ��ü �Լ��� ȣ���Ͽ� HP�� ���ҽ�Ŵ  
					checkState(map,  m);//��, ���� ���� ������ �� ������ �޼����� ���� �Լ�
					if (m.wound)//���� ���� ���
					{
						m.doAttack();
						m.wound = 0;
					}
				}
			}
			else if (turn % 2 == 1)//�������� ����
			{
				// ���� �� ĭ �ö󰡱�
				w.user_y += 1;
				bool inMap = checkXY(w.user_x, mapX, w.user_y, mapY);//�̵��� ���� Ÿ�������� Ȯ���ϴ� �Լ�. �߸��Ǹ� flase�� ���. inMap�� �� ���� �ޱ� ���� ����
				if (inMap == false) {//���� �Լ��� false�� ����� ���
					opti(w.user_x, mapX, w.user_y, mapY);
					continue;
				}
				else {//�Է� ���� �̵� ���� Ÿ���� ���
					cout << "���� �� ĭ �ö󰩴ϴ�." << endl;//�޼����� ���� ����ϴ� �Լ��� ����
					displayMap(map, m.user_x, m.user_y, w.user_x, w.user_y);//��ǥ��
					w.DecreaseHP(1);//�̵��� ��ȿ�Ͽ� �̵� ������ ��ü �Լ��� ȣ���Ͽ� HP�� ���ҽ�Ŵ  
					checkState(map,  w);//��, ���� ���� ������ �� ������ �޼����� ���� �Լ�
					if (w.wound)//���� ���� ���
					{
						w.doAttack();
						w.wound = 0;
					}
				}
			}
		}
		else if (user_input == "��") {//��� ������ ����. x�� y�� ���� �׿� �°� ����
			if (turn % 2 == 0)//�������� ����
			{
				m.user_x -= 1;// ���� �� ĭ �ö󰡱�
				bool inMap = checkXY(m.user_x, mapX, m.user_y, mapY);//�̵��� ���� Ÿ�������� Ȯ���ϴ� �Լ�. �߸��Ǹ� flase�� ���. inMap�� �� ���� �ޱ� ���� ����
				if (inMap == false) {//���� �Լ��� false�� ����� ���
					opti(m.user_x, mapX, m.user_y, mapY);
					continue;
				}
				else {//�Է� ���� �̵� ���� Ÿ���� ���
					cout << "���� �� ĭ �ö󰩴ϴ�." << endl;//�޼����� ���� ����ϴ� �Լ��� ����
					displayMap(map, m.user_x, m.user_y, w.user_x, w.user_y);//��ǥ��
					m.DecreaseHP(1);//�̵��� ��ȿ�Ͽ� �̵� ������ ��ü �Լ��� ȣ���Ͽ� HP�� ���ҽ�Ŵ  
					checkState(map, m);//��, ���� ���� ������ �� ������ �޼����� ���� �Լ�
					if (m.wound)//���� ���� ���
					{
						m.doAttack();
						m.wound = 0;
					}
				}
			}
			else if (turn % 2 == 1)//�������� ����
			{
				// ���� �� ĭ �ö󰡱�
				w.user_x -= 1;
				bool inMap = checkXY(w.user_x, mapX, w.user_y, mapY);//�̵��� ���� Ÿ�������� Ȯ���ϴ� �Լ�. �߸��Ǹ� flase�� ���. inMap�� �� ���� �ޱ� ���� ����
				if (inMap == false) {//���� �Լ��� false�� ����� ���
					opti(w.user_x, mapX, w.user_y, mapY);
					continue;
				}
				else {//�Է� ���� �̵� ���� Ÿ���� ���
					cout << "���� �� ĭ �ö󰩴ϴ�." << endl;//�޼����� ���� ����ϴ� �Լ��� ����
					displayMap(map, m.user_x, m.user_y, w.user_x, w.user_y);//�� ǥ��
					w.DecreaseHP(1);//�̵��� ��ȿ�Ͽ� �̵� ������ ��ü �Լ��� ȣ���Ͽ� HP�� ���ҽ�Ŵ  
					checkState(map, w);//��, ���� ���� ������ �� ������ �޼����� ���� �Լ�
					if (w.wound)//���� ���� ���
					{
						w.doAttack();
						w.wound = 0;
					}
				}
			}
		}
		else if (user_input == "��") {//��� ������ ����. x�� y�� ���� �׿� �°� ����
			if (turn % 2 == 0)//�������� ����
			{
				m.user_x += 1;// ���� �� ĭ �ö󰡱�
				bool inMap = checkXY(m.user_x, mapX, m.user_y, mapY);//�̵��� ���� Ÿ�������� Ȯ���ϴ� �Լ�. �߸��Ǹ� flase�� ���. inMap�� �� ���� �ޱ� ���� ����
				if (inMap == false) {//���� �Լ��� false�� ����� ���
					opti(m.user_x, mapX, m.user_y, mapY);
					continue;
				}
				else {//�Է� ���� �̵� ���� Ÿ���� ���
					cout << "���� �� ĭ �ö󰩴ϴ�." << endl;//�޼����� ���� ����ϴ� �Լ��� ����
					displayMap(map, m.user_x, m.user_y, w.user_x, w.user_y);//��ǥ��
					m.DecreaseHP(1);//�̵��� ��ȿ�Ͽ� �̵� ������ ��ü �Լ��� ȣ���Ͽ� HP�� ���ҽ�Ŵ  
					checkState(map, m);//��, ���� ���� ������ �� ������ �޼����� ���� �Լ�
					if (m.wound)//���� ���� ���
					{
						m.doAttack();
						m.wound = 0;
					}
				}
			}
			else if(turn % 2 == 1)//�������� ����
			{
				// ���� �� ĭ �ö󰡱�
				w.user_x += 1;
				bool inMap = checkXY(w.user_x, mapX, w.user_y, mapY);//�̵��� ���� Ÿ�������� Ȯ���ϴ� �Լ�. �߸��Ǹ� flase�� ���. inMap�� �� ���� �ޱ� ���� ����
				if (inMap == false) {//���� �Լ��� false�� ����� ���
					opti(w.user_x, mapX, w.user_y, mapY);
					continue;
				}
				else {//�Է� ���� �̵� ���� Ÿ���� ���
					cout << "���� �� ĭ �ö󰩴ϴ�." << endl;//�޼����� ���� ����ϴ� �Լ��� ����
					displayMap(map, m.user_x, m.user_y, w.user_x, w.user_y);//���� ǥ��
					w.DecreaseHP(1);//�̵��� ��ȿ�Ͽ� �̵� ������ ��ü �Լ��� ȣ���Ͽ� HP�� ���ҽ�Ŵ  
					checkState(map, w);//��, ���� ���� ������ �� ������ �޼����� ���� �Լ�
					if (w.wound)//���� ���� ���
					{
						w.doAttack();
						w.wound = 0;
					}
				}
			}
		}
		else if (user_input == "����") {//������ �Է� ���� ���
			// TODO: ���� �����ֱ� �Լ� ȣ��
			displayMap(map, m.user_x, m.user_y,w.user_x,w.user_y);
			continue;//������ ���� ���ʰ� �Ѿ�� �ʵ���
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
		bool finish = checkGoal(map, m.user_x, m.user_y,w.user_x,w.user_y);//������ �������� �����ϸ� true�� ��ȯ�ϴ� �Լ��� �� ���� �ޱ� ���� ����
		if (finish == true) {//������ Ʈ�簡 �Ҵ�Ȱ�� ��, �������� ��ǥ�� ���� ��ǲ��ǥ�� ������ ��.
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;//���� �޼��� ��°� ���� ���� ����
			cout << "������ �����մϴ�." << endl;
			break;

			
		}
		turn++;

	}
	return 0;
}


// ������ ����� ��ġ ����ϴ� �Լ�
void displayMap(int map[][mapX], int user_x, int user_y,int user2_x,int user2_y) {//�迭�� �Է� ��ǥ�� �Ű������� ����
	for (int i = 0; i < mapY; i++) {//���� ���θ�ŭ �ݺ�
		for (int j = 0; j < mapX; j++) {//���� �� ���ο��� ���θ�ŭ �ݺ�
			//�� �迭�� Ž���ϵ� �� �迭�� ������ ���� ������ ������ ���, �� �迭�� ������ �������� ������ ���� ��ġ�� ������Ʈ�� ���
			//�� �޼����� ����� �� ���θ� ������ ĭ�� ���
			
			if (user_x == user2_x && user_y == user2_y && user_x == j && user_y == i)
			{
				cout << "  mw  |";
			}
            else if (i == user_y && j == user_x) {//�� �ݺ� �ñ� �� ��ǥ�� �Է���ǥ�� ������
				cout << "   m  |"; // �� �� 1ĭ ���� //������ ���
			}
			else if (i == user2_y && j == user2_x) {//�� �ݺ� �ñ� �� ��ǥ�� �Է���ǥ�� ������
				cout << "   w  |"; // �� �� 1ĭ ���� //������ ���
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
bool checkGoal(int map[][mapX], int user_x, int user_y,int user2_x,int user2_y) {// �Է� ��ǥ���� �迭�� �Ű�������
	// ������ �����ϸ�
	if (map[user_y][user_x] == 4) {//�Է� ��ǥ�� ���� �� �迭�� �������� ������
		cout << "magicina�� �¸��߽��ϴ�." << endl;
		return true;//Ʈ�縦 ���
	}
	else if (map[user2_y][user2_x]==4)
	{
		cout << "worrior�� �¸��߽��ϴ�." << endl;
		return true;//Ʈ�縦 ���
	}
	return false;//if �� ������� ���� �������� �ƴϸ� false�� ���
}

void checkState(int map[][mapX],User& user)
{
	int posState = map[user.user_y][user.user_x];//�� �迭 �ε����� �ִ� ���� ���� ������ ���� �� �� �迭�� ������ �ʱ�ȭ
	switch (posState)//��, �� �迭�� � ���� ����ִ��� Ȯ���ϰ� �׿����� ������ ��.
	{
	case 0://������ ���, �ƹ��͵� ���� ����
		break;
	case 1://�������� ���
		cout << "�������� �������ϴ�.\n";//�������� �����ٴ� �Լ� ���
		break;
	case 2://���� ���� ���
		cout << "���� �������ϴ�. Hp�� 2 �پ��ϴ�.\n";//�޼��� ���
		user.wound++;//���� �������� ǥ���ϱ� ���� ���
	    user.DecreaseHP(2);//�������� ��//��ü �Լ��� ü�� 2�� ����
		break;
	case 3://������ �������
		cout << "������ ȹ���߽��ϴ�. Hp�� 2 �þ�ϴ�.\n";//�޼����� ����ϰ� ȸ������
		user.IncreaseHP(2);//��ü�Լ��� �����Ͽ� 2�� ����
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

bool CheckUser(User user) {
	if (user.GetHP() <= 0)//��ü�� hp�� ��ȯ�ϴ� �Լ� ����Ͽ� ü���� ����.
		return false;
	else
		return true;
}