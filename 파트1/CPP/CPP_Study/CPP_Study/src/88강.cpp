#include <iostream>
#include <vector>
using namespace std;

// 오늘의 주제 : vector

int main()
{
	// STL (Standard Template Library)
	// 프로그래밍할 때 필요한 자료구조/알고리즘들을
	// 템플릿으로 제공하는 라이브러리

	// 컨테이너 (Container) : 데이터를 저장하는 객체 (자료 구조 Data Structure)

	// vector (동적 배열)
	// - vector의 동작 원리 (size/capacity)
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	// ------------------------------------------------------

	// 배열
	// - 배열의 크기를 유동적으로 변경 불가능
	// - 처음부터 크기를 크게 잡는다면 자원 낭비

	const int MAX_SIZE = 10;
	int arr[MAX_SIZE] = {};

	for (int i = 0; i < MAX_SIZE; i++)
		arr[i] = i + 1;

	for (int i = 0; i < MAX_SIZE; i++)
		cout << arr[i] << endl;

	cout << "------------------------------------------------------" << endl;

	// 동적 배열
	// - 매우 매우 중요한 개념 -> 대체 어떤 마법을 부렸길래 배열을 '유동적으로' 사용한 것인가?
	
	// 1) (여유분을 두고) 메모리를 할당한다
	// 2) 여유분까지 꽉 찼으면, 메모리를 증설한다

	// Q1) 여유분은 얼마만큼이 적당할까?
	// Q2) 증설을 얼마만큼 해야할까?
	// Q3) 기존의 데이터를 어떻게 처리해야할까?

	// [ 1 2 3 4 5]
	// 증설 >>
	// [ 1 2 3 4 5       ]

	vector<int> v;
	// vector<int> v(1000);		// resize(1000)과 같은 효과
	// vector<int> v(1000, 0);	// 초기값 설정까지 가능
	vector<int> v2 = v;			// v가 가지고 있던 값, 특징까지 전부 복사

	// size (실제 사용 데이터 개수)
	// 1 2 3 4 5 6 7 ...
	
	// capacity (여유분을 포함한 용량 개수)
	// 1 2 3 4 6 9 13 19 28 42 63

	// v.resize(1000);	// 실제 사용 데이터 개수를 처음부터 지정
						// 배열처럼 v[i] = i; 와 같은 방식으로 사용 가능

	// v.reserve(1000);	// 복사 비용을 줄이기 위해서 
						// 만약 대략적인 사이즈를 이미 알고 있다면
						// 처음부터 capacity를 1000으로 잡아줌

	for (int i = 0; i < 1000; i++)
	{
		// v[i] = i;
		v.push_back(100);
		cout << v.size() << " " << v.capacity() << endl;
	}

	v.clear();	// 데이터 삭제
	// 하지만 이미 늘어난 capacity는 변화 없음
	cout << v.size() << " " << v.capacity() << endl;

	vector<int>().swap(v);	// 이 방식대로 하면 임시 벡터를 생성한 뒤, 
							// 벡터를 서로 교환하고 임시 벡터는 사라지기 때문에
							// capacity 또한 초기화 가능
	cout << v.size() << " " << v.capacity() << endl;

	return 0;
}