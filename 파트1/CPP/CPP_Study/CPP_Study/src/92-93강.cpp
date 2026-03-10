#include <iostream>
using namespace std;
#include <vector>
#include <list>

// 오늘의 주제 : list

// ----------------------------------------------

// vector : 동적 배열
// [[1][2][3][4][5][6]]	// 연속된 공간에 저장
// ->
// [[1][2][3][4][5][6][7][ ][ ]]

//-----------------------------------------------

// 단일 / 이중 / 원형
// list : 연결 리스트 
// [1]      ->     [2]      ->     [3]      ->     [4]      ->     [5] 
// [1]     <->     [2]     <->     [3]     <->     [4]     <->     [5]
// [1]     <->     [2]     <->     [3]     <->     [4]     <->     [5]     <->

// STL의 list는 이중 리스트로 구현되어있음
// [1]     <->     [2]     <->     [3]     <->     [4]     <->     [5]     <->     [_Myhead : end()] : 더미 노드 (유효범위 확인용)     <->  

class Node
{
public:
	Node*	_next;		// 다음 노드 주소
	Node*	_prev;		// 이전 노드 주소
	int		_data;		
};

// 중간 삽입
// [1]     <->     [2]     <->     [3]     <->     [4]     <->     [5]
// + [100]
// [1]     <->     [2]     <->     [100]     <->     [3]     <->     [3]     <->     [5]

// 중간 삭제
// [1]     <->     [2]     <->     [3]     <->     [4]     <->     [5]
// - [3]
// [1]     <->     [2]     <->     [4]     <->     [5]             [3]

// 처음/끝도 똑같음 -> 삽입/삭제 효율적임

// 하지만 연속된 공간에 데이터가 저장되어있지 않기 때문에 임의 접근(Random Access)가 꽤 비효율적임
// - vector는 시작 주소를 기준으로 주소 계산이 가능하지만,
// - list는 포인터를 타고 다음 노드로 이동하는 것을 반복하면서 직접 타겟을 찾아야함. 즉, 임의 접근 자체가 불가능함

// 삽입/삭제가 효율적임에도 불구하고 단점이 더 크기 때문에 보통 list 보다 vector를 우선해서 사용함
// 또한, 삽입/삭제 자체는 효율적이지만 삽입/삭제를 하기 위해 결국 타겟 노드를 탐색해야하는데, 이 과정 자체가 비효율적임


int main()
{
	// list (연결 리스트) 
	// - list의 동작 원리
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	list<int> li;

	for(int i = 0; i < 100; i++) 
		li.push_back(i);
	
	// li.push_front(10);

	int size = li.size();
	
	// li.capacity();	// 없음

	int first = li.front();
	int last = li.back();

	// li[3] = 10;		// 없음

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	// list<int>::iterator itTest1 = --itBegin;			// X - itBegin의 이전 노드는 더미 노드이지만 경고 메세지와 함께 이동하지 못하도록 막아놓은 것을 알 수 있음
	list<int>::iterator itTest2 = ++itBegin;			// O - itBegin이 시작 노드이므로 ++를 하면 다음 노드로 이동하게 됨
	list<int>::iterator itTest3 = --itEnd;				// O - itEnd가 더미 노드이므로 --를 하면 리스트의 가장 마지막 요소로 이동하게 됨
	// list<int>::iterator itTest4 = ++itEnd;			// X - 첫번째와 같은 원리로 이동하지 못함. 더미 노드로 이동하거나 더미 노드를 경유하는 것은 불가능함
	
	// list<int>::iterator itTest5 = itBegin + 10;		// 이동 원리가 비효율적이기 때문에 문법적으로 아예 구현되어있지 않음 

	int* ptrBegin = &(li.front());
	int* ptrEnd = &(li.back());

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << endl;
	}

	li.insert(itBegin, 100);

	//li.erase(li.begin());
	//li.pop_front();

	li.remove(10);	// 10은 전부 삭제
	// vector는 삭제가 비효율적이기 때문에 remove()가 존재하지 않음

	// * 임의 접근이 안된다
	// * 중간 삼입/삭제 빠르다...? 모순
	// Ex) 50번 인덱스에 있는 데이터를 삭제
	list<int>::iterator it = li.begin();
	for (int i = 0; i < 50; i++)	// 엄청 비효율적임
		++it;
	li.erase(it);	// 이 부분은 효율적임


	// 아래와 같은 방식으로 itRemember라는 iterator로 위치를 기억해서 효율적으로 삭제하는 것은 가능함
	list<int> li2;
	list<int>::iterator itRemember;

	for (int i = 0; i < 100; i++)
	{
		if (i == 50)
		{
			itRemember = li2.insert(li2.end(), i);	// 삽입할 때부터 삭제할 노드를 기억해둠
		}
		else
		{
			li2.push_back(i);
		}
	}

	li2.erase(itRemember);		// 기억해둔 노드의 위치를 바탕으로 효율적으로 삭제

	return 0;
}