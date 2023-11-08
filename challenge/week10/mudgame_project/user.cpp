#include "user.h"

void User::DecreaseHP(int dec_hp)
{
	hp -= dec_hp;
}
int User::GetHP()
{
	return hp;
}