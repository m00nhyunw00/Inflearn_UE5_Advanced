#include <iostream>
using namespace std;

// 오늘의 주제 : 캐스팅 (타입 변환)

// 1) static_cast
// 2) dynamic_cast
// 3) const_cast
// 4) reinterpret_cast

void PrintName(char* str)
{
	cout << str << endl;
}

class Player
{
public:
	virtual ~Player() { }
};

class Knight : public Player
{
public:

};

class Archer : public Player
{
public:

};

class Dog
{
public:

};

int main()
{
	// 1. static_cast : 타입 원칙에 비추어볼 때 상식적인 캐스팅만 허용해준다 -------------------------------------------------

	// - 1) int <-> float
	// - 2) Player* -> Knight* (다운캐스팅) << 던, 안정성은 보장 못함

	int hp = 100;
	int maxHp = 200;
	// float ratio = (float)hp / maxHp;
	float ratio = static_cast<float>(hp) / maxHp;

	// 부모 -> 자식 / 자식 -> 부모
	// Player* p = new Archer(); << 위험한 케이스
	Player* p = new Knight();

	// 만약 p의 원본 데이터의 타입을 알 수 없다면 이를 확인할 수 있는 안전장치를 마련할 필요가 있음
	// 예를 들어 멤버 변수로 _itemType 같은 것을 두어 확인할 수 있도록 할 수도 있을 것임
	// 또는, dynamic_cast를 활용하면 됨

	Knight* k1 = static_cast<Knight*>(p);


	// 2. dynamic_cast : 상속 관계에서의 안전 형변환 --------------------------------------------------------------------------
	
	// RTTI (Runtime Type Information)
	// 다형성을 활용하는 방식
	// - virtual 함수를 하나라도 만들면, 객체의 메모리에 가상 함수 테이블 (vftable) 주소가 기입된다
	// - 만약 잘못된 타입으로 캐스팅을 했으면, nullptr 반환 ****************
	// 이를 이용해서 맞는 타입으로 캐스팅을 했는지 확인을 할 수 있어 유용함

	Knight* k2 = dynamic_cast<Knight*>(p);


	// 3. const_cast : const를 붙이거나 떼거나 --------------------------------------------------------------------------------

	PrintName(const_cast<char*>("Moon"));


	// 4. reinterpret_cast ----------------------------------------------------------------------------------------------------
	// 가장 위험하고 강력한 형태의 캐스팅
	// 're-interpret' : 다시-간주하다/생각하다
	// - 포인터랑 전혀 관계없는 다른 타입 변환 등

	__int64 address = reinterpret_cast<__int64>(k2);

	Dog* dog1 = reinterpret_cast<Dog*>(k2);

	void* p = malloc(1000);
	Dog* dog2 = reinterpret_cast<Dog*>(p);	// malloc으로 할당받았을 경우, 그 공간이 클래스로 사용될 것인지를 모르기 때문에
											// static_cast를 사용하면 오류가 발생함 -> 강제로 reinterpret_cast를 활용

	cout << address << endl;

	return 0;
}