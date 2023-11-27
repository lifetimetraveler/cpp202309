#include "user.h"
void User::IncreaseHP(int inc_hp)
{
	hp += inc_hp;
}
void User::DecreaseHP(int dec_hp)
{
	hp -= dec_hp;
}
int User::GetHP()
{
	return hp;
}
void User::SetHP(int hhp)
{
	hp = hhp;
}
void User::doAttack()
{
	cout << "공격합니다" << endl;
}
void Magician::doAttack()
{
	cout << "마법 사용" << endl;
}
void Warrior::doAttack()
{
	cout << "베기 사용" << endl;
}