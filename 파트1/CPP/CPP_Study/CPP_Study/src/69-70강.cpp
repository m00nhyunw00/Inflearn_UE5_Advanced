#include <iostream>
using namespace std;

// 오늘의 주제 : 타입 변환 (포인터)

class Knight
{
	int _hp;
};

class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
	}

	Item(int itemType) : _itemType(itemType)
	{
		cout << "Item(int itemType)" << endl;
	}

	Item(const Item& item)
	{
		cout << "Item(const Item& item)" << endl;
	}

	virtual ~Item()
	{
		cout << "~Item()" << endl;
	}

	virtual void Test()
	{
		cout << "Test Item" << endl;
	}

public:
	int _itemType = 0;
	int _itemDbId = 0;

	char _dummy[4096] = {};	// 이런 저런 정보들로 인해 비대해진
};

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR = 2,
};

class Weapon : public Item
{
public:
	Weapon() : Item(IT_WEAPON)
	{
		cout << "Weapon()" << endl;
		_damage = rand() % 100;
	}

	virtual ~Weapon()
	{
		cout << "~Weapon()" << endl;
	}

	virtual void Test()
	{
		cout << "Test Weapon" << endl;
	}

public:
	int _damage;
};

class Armor : public Item
{
public:
	Armor() : Item(IT_ARMOR)
	{
		cout << "Armor()" << endl;
		_defence = rand() % 10;

	}

	virtual ~Armor()
	{
		cout << "~Armor()" << endl;
	}

	virtual void Test()
	{
		cout << "Test Armor" << endl;
	}

public:
	int _defence;
};

void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{
	item->Test();
}

int main()
{
	// 연관성이 없는 클래스 사이의 포인터 변환 테스트

	{
		// Stack [ 주소 ] -> Heap [ _hp(4) ]
		Knight* knight = new Knight();

		// 암시적으로는 No
		// 명시적으로는 Ok

		// Stack [ 주소 ]
		Item* item = (Item*)knight;
		item->_itemType = 2;
		item->_itemDbId = 1;	// 건드리면 안되는 부분을 건드리는 중 (메모리 오염)

		// delete knight;	// 다행히 이 경우에는 delete를 하려고 하면 
							// 메모리의 앞뒤에 일부러 추가된 0xfdfdfdfd와 같은 디버그 메모리 패턴을 통해 에러를 발생시킴
	}

	// 자식 -> 부모
	{
		Item* item = new Item();

		// 명시적으로만 가능
		Weapon* weapon = (Weapon*)item;

		// delete item;	// 컴파일러가 에러를 발생시켜 메모리 오염을 사전에 감지할 수 있음
	}

	// 부모 -> 자식
	{
		Weapon* weapon = new Weapon();
		
		// 암시적으로도 가능
		Item* item = weapon;

		TestItemPtr(item);

		delete weapon;
		item = nullptr;
	}

	// 명시적으로 타입 변환할 떄는 항상 항상 조심해야 한다!
	// 암시적으로 될 때는 안전하다?
	// -> 평생 명시적으로 타입 변환(캐스팅)은 안하면 되는거 아닌가?

	Item* inventory[20] = {};

	srand((unsigned int)time(nullptr));

	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 2; // 9~1
		switch (randValue)
		{
		case 0:
			inventory[i] = new Weapon();
			break;
		case 1:
			inventory[i] = new Armor();
			break;
		}
	}

	for (int i = 0; i < 20; i++) 
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		if (item->_itemType == IT_WEAPON)
		{	
			// item의 원물 자체가 Weapon 타입이였기 때문에 변환해도 안전함
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
		}
		else if (item->_itemType == IT_ARMOR)
		{
			// item의 원물 자체가 Armor 타입이였기 때문에 변환해도 안전함
			Armor* armor = (Armor*)item;
			cout << "Armor Defence : " << armor->_defence << endl;
		}
	}

	// ************************* 매우 매우 매우 매우 중요함 *******************************
	// 상속 관계가 존재할 경우, 소멸자에 반드시 virtual을 붙여주자!!

	// 기존의 방식대로라면, 아래와 같이 메모리를 해제하면 원물의 타입을 무시하고 Item의 소멸자만 호출됨
	//for (int i = 0; i < 20; i++)
	//{
	//	Item* item = inventory[i];
	//	if (item == nullptr)
	//		continue;

	//	delete item;
	//}

	// 아래와 같은 방법으로 해제해야 안전함
	//for (int i = 0; i < 20; i++)
	//{
	//	Item* item = inventory[i];
	//	if (item == nullptr)
	//		continue;

	//	if (item->_itemType == IT_WEAPON)
	//	{
	//		Weapon* weapon = (Weapon*)item;
	//		delete weapon;
	//	}
	//	else if (item->_itemType == IT_ARMOR)
	//	{
	//		Armor* armor = (Armor*)item;
	//		delete armor;
	//	}
	//}

	// 하지만 소멸자에 virtual을 붙이면 아래와 같이 사용 가능
	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		delete item;
	}

	return 0;
}