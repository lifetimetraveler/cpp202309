#include <iostream>
using namespace std;

class User {

	int hp;//������ ü��
public:
	User(int hhp) { hp = hhp; }//�Է¹��� ������ ü���� �ʱ�ȭ�ϴ� ������
	void IncreaseHP(int inc_hp);//ü�� ������ �Լ�
	void DecreaseHP(int dec_hp);//ü�� ���ҿ� �Լ�
	int GetHP();//ü�� ��ȯ�ϴ� �Լ�

};
