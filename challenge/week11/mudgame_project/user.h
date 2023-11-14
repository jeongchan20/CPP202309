#include<iostream>
using namespace std;

//User cpp에서 함수식을 적어놓아서 헤더파일에는 원형만 적어서 사용
class User {

private:
	int hp;
	
	
public:
	int GetHP();
	void DecreaseHP(int dec_hp);	
	void IncreaseHP(int inc_hp);
	User(){hp= 20; }
	
};
