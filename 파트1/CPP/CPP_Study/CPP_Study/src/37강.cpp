#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 연산

// 1) 주소 연산자
// 2) 산술 연산자
// 3) 간접 연산자
// 4) 간접 멤버 연산자

struct Player
{
	int hp;
	int damage;
};

int main()
{
	int number = 1;

	// 1) 주소 연산자 (&)
	// - 해당 변수의 주소를 알려주세요~
	// - 더 정확히 말하면 해당 변수 타입(TYPE)에 따라서 *TYPE 반환

	int* pointer = &number;

	///////////////////////////////////////////////////////////

	// 2) 산술 연산자 (+ -)
	// - 주소값이 1 증가하는 것이 아니라 포인터가 나타내는 변수의 타입 크기 만큼 증가
	// -- 다음에 저장된 변수로 이동하는 개념

	pointer = pointer + 1;	// pointer는 int* 였으므로 int형의 크기인 4(바이트)가 증가함 
	pointer++;
	++pointer;
	pointer += 1;

	///////////////////////////////////////////////////////////

	// 3) 간접 연산자 (*)
	// - 포탈 타고 해당 주소로 이동

	number = 3;
	// ==
	*pointer = 3;

	Player player;
	player.hp = 100;
	player.damage = 10;

	Player* playerPtr = &player;

	(*playerPtr).hp = 200;
	(*playerPtr).damage = 200;

	///////////////////////////////////////////////////////////

	// 4) 간접 멤버 연산자 (->) 
	// - (*playerPtr). 과 같은 개념

	playerPtr->hp = 300;
	playerPtr->damage = 300;


	return 0;
}