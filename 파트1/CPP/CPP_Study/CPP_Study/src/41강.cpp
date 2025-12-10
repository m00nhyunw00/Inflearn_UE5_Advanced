#include <iostream>
using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

int main()
{
	// TYPE 이름[개수];

	// 배열의 크기는 상수여야 함 (VS 컴파일러 기준)
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];
	

	// 여태껏 변수들의 [이름]은 바구니의 이름이었음
	// 그런데 배열은 [이름] 조금 다른게 동작한다
	
	// StatInfo players[10];
	// players = monsters	// 불가능

	// 그럼 배열의 이름은 뭐지?
	// 배열의 이름은 곧 배열의 시작 주소
	// 정확히는 시작 위치를 가리키는 TYPE* 포인터
	
	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	StatInfo& monster_2 = *(monsters + 2);
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	// [주의] 이거는 완전 다른 의미다.
	StatInfo temp = *(monsters + 2);	// 단순 값 복사
	temp.hp = 300;
	temp.attack = 30;
	temp.defence = 3;

	// 위 과정을 자동화한 버전
	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = *(monsters + i);
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defence = (i + 1);
	}

	// 근데 *(monster + i) 너무 불편하고 가독성이 떨어진다... 더 편한 방법?
	// 인덱스!!
	// 배열은 0번부터 시작, N번째 인덱스에 해당하는 데이터에 접근하려면 배열이름[N]
	// *(monster + i) = monster[i]

	for (int i = 0; i < 10; i++)
	{
		monsters[i].hp = 100 * (i + 1);
		monsters[i].attack = 10 * (i + 1);
		monsters[i].defence = (i + 1);
	}

	// 배열 초기화 문법 몇가지
	int numbers[5] = {};	// 기본값 0으로 초기화
	int numbers1[10] = { 1,2,3,4,5 };	// 설정한 애들은 설정한 값들로, 나머지 값들은 0으로 초기화
	int numbers2[] = { 1,2,3,4,5,6,7,8,9,10 };	// 데이터 개수만큼의 크기에 해당하는 배열로 생성

	char helloStr[] = { 'H', 'e', 'l', 'l', 'o', '\0' };

	return 0;
}