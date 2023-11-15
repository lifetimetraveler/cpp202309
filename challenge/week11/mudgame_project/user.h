#include <iostream>
using namespace std;

class User {

	int hp;//유저의 체력
public:
	User(int hhp) { hp = hhp; }//입력받은 값으로 체력을 초기화하는 생성자
	void IncreaseHP(int inc_hp);//체력 증가용 함수
	void DecreaseHP(int dec_hp);//체력 감소용 함수
	int GetHP();//체력 반환하는 함수

};
