#include <iostream>
using namespace std;

class User {

	int hp;//������ ü��
	
public:
    int user_x=0;//������ x��ǥ
	int user_y=0;//������ y��ǥ
	int wound = 0;//������ ���� ������ 1�� �����.
	User(int hhp) { hp = hhp; }//�Է¹��� ������ ü���� �ʱ�ȭ�ϴ� ������
	void IncreaseHP(int inc_hp);//ü�� ������ �Լ�
	void DecreaseHP(int dec_hp);//ü�� ���ҿ� �Լ�
	int GetHP();//ü�� ��ȯ�ϴ� �Լ�
	void doAttack();
	void SetHP(int hhp);//ü���� �ʱ�ȭ�ϱ����� �Լ�
};
class Magician:public User//������ Ŭ����
{
	
public:
	
	Magician(int hp) :User(hp){}//������
	void doAttack();
};
class Warrior:public User//������ Ŭ����
{
public:
	Warrior(int hp) :User(hp) {}//������
	void doAttack();
};