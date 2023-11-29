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
		cout << "TVÅµ´Ï´Ù" << endl;
	}
	void TurnOFF() override {
		cout << "TV ²ü´Ï´Ù" << endl;
	}
};

class Refrigerator :public RemoteControl {
	void TurnON() override {
		cout << "³ÃÀå°í Åµ´Ï´Ù" << endl;
	}
	void TurnOFF() override {
		cout << "³ÃÀå°í ²ü´Ï´Ù" << endl;
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