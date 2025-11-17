#include <iostream>
using namespace std;

// 오버로딩 (중복 정의 : 함수 이름의 재사용)

int Add(int a, int b)
{
	return a + b;
}

float Add(float a, float b)
{
	return a + b;
}

// 인자 타입과 수가 서로 같다면 오버로딩이 불가능
//int Add(float a, float b)
//{
//	return a + b;
//
//}

void SetPlayerInfo(int hp, int mp, int guildId, int attack = 0, int shield = 0)
{
	// 생략
}

int main()
{
	int result = Add(1.5f, 2.1f);
	cout << result;

	SetPlayerInfo(10000, 5000, 13579);			// attack, shield 생략
	SetPlayerInfo(10000, 5000, 13579, 100);		// shield 생략
	SetPlayerInfo(10000, 5000, 13579, 0, 100);	// attack만 생략하고 shield만 설정하는 것은 불가능하기 때문에 이와 같이 사용

	return 0;
}