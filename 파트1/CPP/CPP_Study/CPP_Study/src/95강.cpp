#include <iostream>
using namespace std;
#include <vector>
#include <deque>

// 오늘의 주제 : deque

int main()
{
	// 시퀀스 컨테이너 (Sequence Container)
	// 데이터가 삽입 순서대로 나열되는 형태
	// vector list deque

	// vector : 동적 배열
	// [             ]		]       ]          ]
	
	// list : 이중 연결 리스트
	// [ ] <-> [ ] <-> [ ] <-> [ ]
	
	// deque : Double-ended queue (데크)
	// [		]
	// [		]
	// [		]

	// vector와 마찬가지로 배열 기반으로 동작
	// 다만 메모리 할당 정책이 다르다

	vector<int> v(3, 1);
	deque<int> dq(3, 1);

	v.push_back(2);
	v.push_back(2);
	dq.push_back(2);
	dq.push_back(2);

	dq.push_front(3);
	dq.push_front(3);

	// deque의 동작/원리
	// dq 현재 상태
	// [x x 3 3]
	// [1 1 1 2]
	// [2 x x x]

	// 벡터와 다르게 양방향 자료 구조이기 때문에 시작에 삽입/삭제하는 것도 빠르다는 장점이 있다.

	// - 중간 삽입/삭제 (비효율적 - vector와 같은 이유로)
	// - 처음/끝 삽입/삭제 (효율적)
	// - 임의 접근 (지원함)

	dq[3] = 10;
	cout << dq[3] << endl;

	// 그렇다면 독립된 데이터 블록에 데이터들이 그룹을 지어서 저장되어있는데 어떻게 임의 접근이 빠르게 이루어질까?
	// iterator를 까보면  어떠한 데이터가 어떠한 블록의 어디에 소속되어있는지가 저장된다는 것을 알 수 있다.
	// 즉 몇동, 몇호의 데이터인지에 대한 정보가 따로 테이블로 관리된다.

	

	return 0;
}