#include<iostream>
using namespace std;

//User cpp���� �Լ����� ������Ƽ� ������Ͽ��� ������ ��� ���
class User {

private:
	int hp;
	
	
public:
	int GetHP();
	void DecreaseHP(int dec_hp);	
	void IncreaseHP(int inc_hp);
	User(){hp= 20; }
	void doAttack();
	
};
class Magician :public User {
public:
	void doAttack();
};

class Warrior :public User {
public:
	void doAttack();
};