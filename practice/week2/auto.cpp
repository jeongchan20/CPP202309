#include<iostream>
using namespace std;

//auto�� ������ �ڵ����� ����������!
auto add(int x, int y) {
	return x + y;
}

int main()
{
	auto sum = add(5, 6);
	cout << sum;
	return 0;
}