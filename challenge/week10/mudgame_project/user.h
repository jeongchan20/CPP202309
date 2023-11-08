#include<iostream>
using namespace std;

//User cpp에서 함수식을 적어놓아서 헤더파일에는 원형만 적어서 사용
class User {

public:
	int hp;
	void DecreaseHP(int dec_hp);
		
	int GetHP();

};
