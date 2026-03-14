#include <iostream>
using namespace std;
#include <map>
#include <set>

// 오늘의 주제 : set, multimap, multiset

int main()
{
	// set
	// - (Key == value)
	set<int> s;


	// 넣고
	s.insert(10);
	s.insert(30);
	s.insert(70);
	s.insert(90);
	s.insert(20);

	// s[a] = b; 같은 문법은 막혀있음 -> value가 따로 없기 때문
	

	// 빼고
	s.erase(30);
	

	// 찾고
	set<int>::iterator findIt = s.find(50);
	if (findIt == s.end())
		cout << "못찾음" << endl;
	else
		cout << "찾음" << endl;
	

	// 순회하고
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
		cout << *it << endl;


	cout << "--------------------------------------------------------" << endl;


	// multimap
	multimap<int, int> mm;


	// 넣고
	mm.insert(make_pair(1, 100));
	mm.insert(make_pair(1, 200));
	mm.insert(make_pair(1, 300));
	mm.insert(make_pair(2, 400));
	mm.insert(make_pair(2, 500));
	mm.insert(make_pair(3, 600));

	// mm[1] = 500; 같은 문법은 막혀있음


	// 빼고
	unsigned int count = mm.erase(3);		// Key가 1인 값 전부 삭제, count에는 삭제된 데이터수가 저장됨
	

	// 찾고
	multimap<int,int>::iterator itFind = mm.find(1);		// Key가 1인 값 중 첫번째 데이터만 발견
	if (itFind != mm.end())
		mm.erase(itFind);		// 첫번째 데이터 삭제


	// 순회하고
	for (multimap<int, int>::iterator it = mm.begin(); it != mm.end(); ++it)
		cout << it->first << " " << it->second << endl;
	cout << endl;

	// - 두가지 방법으로 Key값이 1인 데이터들을 전부 찾을 수 있음
	
	// -- 1)
	pair<multimap<int, int>::iterator, multimap<int, int>::iterator> itPair;	// Key가 1인 값 
	itPair = mm.equal_range(1);

	for (multimap<int, int>::iterator it = itPair.first; it != itPair.second; ++it)
		cout << it->first << " " << it->second << endl;
	cout << endl;

	// -- 2)
	multimap<int, int>::iterator itBegin = mm.lower_bound(1);
	multimap<int, int>::iterator itEnd = mm.upper_bound(1);

	for (multimap<int, int>::iterator it = itBegin; it != itEnd; ++it)
		cout << it->first << " " << it->second << endl;


	cout << "--------------------------------------------------------" << endl;


	// multiset
	multiset<int> ms;


	// 넣고
	ms.insert(100);
	ms.insert(100);
	ms.insert(100);
	ms.insert(200);
	ms.insert(300);


	// 찾고
	multiset<int>::iterator findIt2 = ms.find(100);	// 첫번째 요소 찾음

	// 순회하고
	// - 두가지 방법으로 Key값이 100인 데이터들을 전부 찾을 수 있음

	// -- 1)
	pair<multiset<int, int>::iterator, multiset<int, int>::iterator> itPair2;
	itPair2 = ms.equal_range(100);
	
	for (multiset<int>::iterator it = itPair2.first; it != itPair2.second; ++it)
		cout << *it << endl;
	cout << endl;

	// -- 2)
	multiset<int>::iterator itBegin2 = ms.lower_bound(100);
	multiset<int>::iterator itEnd2 = ms.upper_bound(100);

	for (multiset<int>::iterator it = itBegin2; it != itEnd2; ++it)
		cout << *it << endl;

	return 0;
} 