#include <iostream>
#include <stdlib.h>
using namespace std;
#include "Player.h"

// 오늘의 주제 : 전방선언

int main()
{
	// Player는 몇 바이트?
	// int 2개 = 2 * 4 = 8바이트
	// sizeof(Mosnter*) = 4 or 8바이트
	// 현재는 32비트 기준이므로 12바이트

	Player p1;	// 지역 변수 (Stack)

	Player* p2 = new Player();	// 동적 할당 (Heap)

	p1._target3 = p2;

	return 0;
}
