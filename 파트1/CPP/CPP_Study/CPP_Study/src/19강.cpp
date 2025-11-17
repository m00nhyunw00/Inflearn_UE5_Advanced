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

	// 비교 연산
#pragma region 비교 연산

	isSame = (a == b);
	
	isDifferent = (a != b);

	isGreater = (a > b);
	isGreater = (a >= b);

	isSmaller = (a < b);
	isSmaller = (a <= b);

#pragma endregion


	// 논리 연산
#pragma region 논리 연산
	
	// ! not
	test = !isSame;		 

	// && and
	test = (hp <= 0 && isInvincible == false);	// 죽음

	// || or
	test = (hp > 0 || isInvincible == true);	// 생존

#pragma endregion
}