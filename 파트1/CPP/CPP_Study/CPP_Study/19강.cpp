#include <iostream>
using namespace std;

int a = 1;
int b = 2;

bool isSame;
bool isDifferent;
bool isGreater;
bool isSmaller;

bool test;

int hp = 100;
bool isInvincible = true;

int main() {

	// �� ����
#pragma region �� ����

	isSame = (a == b);
	
	isDifferent = (a != b);

	isGreater = (a > b);
	isGreater = (a >= b);

	isSmaller = (a < b);
	isSmaller = (a <= b);

#pragma endregion


	// �� ����
#pragma region �� ����
	
	// ! not
	test = !isSame;		 

	// && and
	test = (hp <= 0 && isInvincible == false);	// ����

	// || or
	test = (hp > 0 || isInvincible == true);	// ����

#pragma endregion
}