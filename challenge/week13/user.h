#include <iostream>
using namespace std;

class User {

	int hp;//유저의 체력
	
public:
int user_x;
	int user_y;

	User(int hhp) { hp = hhp; }//입력받은 값으로 체력을 초기화하는 생성자
	void IncreaseHP(int inc_hp);//체력 증가용 함수
	void DecreaseHP(int dec_hp);//체력 감소용 함수
	int GetHP();//체력 반환하는 함수
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