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
	cout << "�����մϴ�" << endl;
}
void Magician::doAttack()
{
	cout << "���� ���" << endl;
}
void Warrior::doAttack()
{
	cout << "���� ���" << endl;
}