#include <iostream>
using namespace std;

class User {

	int hp;//������ ü��
	
public:
int user_x;
	int user_y;

	User(int hhp) { hp = hhp; }//�Է¹��� ������ ü���� �ʱ�ȭ�ϴ� ������
	void IncreaseHP(int inc_hp);//ü�� ������ �Լ�
	void DecreaseHP(int dec_hp);//ü�� ���ҿ� �Լ�
	int GetHP();//ü�� ��ȯ�ϴ� �Լ�
	void doAttack();
};
class Magician:public User
{
	
public:
	
	Magician(int hp) :User(hp){}
	void doAttack();
};
class Warrior:public User
{
public:
	Warrior(int hp) :User(hp) {}
	void doAttack();
};