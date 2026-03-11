#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>

// 오늘의 주제 : map

class Player
{
public:
	Player() : _playerId(0) { }

	Player(int playerId) : _playerId(playerId) { }
public:
	int _playerId;
};

template<typename T1, typename T2>
struct Pair
{
	T1 t1;
	T2 t2;
};

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	// 연관 컨테이너

	// vector가 비효율적인 상황
	{
		vector<Player*> v;

		for (int i = 0; i < 100000; i++)
		{
			Player* p = new Player(i);

			v.push_back(p);
		}

		// 5만명 퇴장
		for (int i = 0; i < 50000; i++)
		{
			int randIndex = rand() % v.size();

			Player* p = v[randIndex];
			delete p;

			v.erase(v.begin() + randIndex);
		}


		// (ID = 2만 Player) 가 (ID = 1만 Player)를 공격하고 싶어요
		// Q) ID = 1만인 Player를 찾아주세요
		bool found = false;

		for (int i = 0; i < v.size(); i++)
		{
			if (v[i]->_playerId == 10000)
			{
				found = true;
				break;
			}
		}	// 매우 비효율적

		// vector, list의 치명적인 단점
		// -> 원하는 조건에 해당하는 데이터를 빠르게 찾을 수 [없다]
	}

	// map : 균형 이진 트리 (AVL)
	// - 노드 기반

	class Node
	{
	public:
		Node* _left;
		Node* _right;

		pair<int, Player*> _data;
		//int _key;
		//Player* _value;
	};

	// (Key, Value)
	map<int, int> m;

	// insert()는 같은 키의 데이터를 여러번 넣을 경우, 덮어쓰지 않고 최초로 넣은 값만 유지됨
	//pair<map<int, int>::iterator, bool> ok;
	//ok = m.insert(make_pair(1, 100));		// ok = (1,100), true
	//ok = m.insert(make_pair(1, 200));		// ok = (1,100), false

	// 10만명 입장
	for (int i = 0; i < 100000; i++)
	{
		m.insert(pair<int, int>(i, i * 100));
	}

	// erase()는 여러번 해줘도 문제가 안생김
	//unsigned int count = 0;
	//count = m.erase(10000);		// count = 1
	//count = m.erase(10000);		// count = 0

	// 최대 5만명 퇴장
	for (int i = 0; i < 50000; i++)
	{
		int randomValue = rand() % 50000;

		m.erase(randomValue);
	}

	// Q) ID = 1만인 Player 찾고 싶다!
	// A) 매우 빠르게 찾을 수 있음
	map<int, int>::iterator findIt = m.find(10000);
	if (findIt != m.end())
	{
		cout << "찾음" << endl;
	}
	else
	{
		cout << "못찾음" << endl;
	}

	// map 순회
	// 사실 이렇게 단순히 전부 순회하는 것은 vector가 빠름
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		pair<const int, int>& p = (*it);

		int key = p.first;
		key = (*it).first;
		key = it->first;

		int value = p.second;

		/// cout << key << " " << value << endl;
	}

	// 없으면 추가하고, 있으면 수정
	// 1) find() 응용하는 방법
	map<int, int>::iterator findIt2 = m.find(10000);
	if (findIt2 != m.end())
	{
		findIt2->second = 200;
	}
	else
	{
		m.insert(make_pair(10000, 200));
	}
	// 2) 인덱스 활용
	m[5] = 500;		// 5라는 Key값이 있다면 value를 500로 수정, 없다면 (5,500) 삽입 
	// [] 연산자 사용할 때 주의
	// 대입을 하지 않더라도 (Key/Value) 형태의 데이터가 추가된다!
	m.clear();
	for (int i = 0; i < 10; i++)
	{
		cout << m[i] << endl;	// (i,0)을 강제로 삽입을 하게 됨
								// 삽입을 원치 않는 경우에는 find()를 활용하면 됨
	}

	// 넣고			insert, []
	// 빼고			erase
	// 찾고			find
	// 반복자		map<T1,T2>::iterator it  
	//				pair<const T1, T2>& p = (*it)

	return 0;
}