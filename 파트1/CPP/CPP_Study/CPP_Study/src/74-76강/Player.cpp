#include "Player.h"
#include <iostream>
using namespace std;

void Player::PrintInfo()
{
	cout << "------------------------" << endl;
	cout << "[플레이어 정보] HP: " << _hp << " ATT: " << _attack << " DEF: " << _defence << endl;
	cout << "------------------------" << endl;
}
