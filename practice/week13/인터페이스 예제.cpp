#include<iostream>
using namespace std;

class RemoteControl {
public:
	virtual void TurnON() = 0;
	virtual void TurnOFF() = 0;
};

class Televison:public RemoteControl
{
	void TurnON() override {
		cout << "TVŵ�ϴ�" << endl;
	}
	void TurnOFF() override {
		cout << "TV ���ϴ�" << endl;
	}
};

class Refrigerator :public RemoteControl {
	void TurnON() override {
		cout << "����� ŵ�ϴ�" << endl;
	}
	void TurnOFF() override {
		cout << "����� ���ϴ�" << endl;
	}
}; 

int main() {
	RemoteControl* remoteTV = new Televison();
	remoteTV->TurnON();
	remoteTV->TurnOFF();

	RemoteControl* remoteRefrigerator = new Refrigerator();
	remoteRefrigerator->TurnON();
	remoteRefrigerator->TurnOFF();

	delete remoteTV, remoteRefrigerator;
	return 0;
}