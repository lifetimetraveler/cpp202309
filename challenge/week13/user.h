#include <iostream>
using namespace std;

class User {

	int hp;//유저의 체력
	
public:
    int user_x=0;//유저의 x좌표
	int user_y=0;//유저의 y좌표
	int wound = 0;//유저가 적을 만나면 1로 만든다.
	User(int hhp) { hp = hhp; }//입력받은 값으로 체력을 초기화하는 생성자
	void IncreaseHP(int inc_hp);//체력 증가용 함수
	void DecreaseHP(int dec_hp);//체력 감소용 함수
	int GetHP();//체력 반환하는 함수
	void doAttack();
	void SetHP(int hhp);//체력을 초기화하기위한 함수
};
class Magician:public User//매지션 클래스
{
	
public:
	
	Magician(int hp) :User(hp){}//생성자
	void doAttack();
};
class Warrior:public User//워리어 클래스
{
public:
	Warrior(int hp) :User(hp) {}//생성자
	void doAttack();
};