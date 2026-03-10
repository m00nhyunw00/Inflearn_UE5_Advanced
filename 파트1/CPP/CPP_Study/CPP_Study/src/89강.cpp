#include <iostream>
#include <vector>
using namespace std;

// 오늘의 주제 : vector

int main()
{
	// 컨테이너 (Container) : 데이터를 저장하는 객체 (자료 구조 Data Structure)

	// vector (동적 배열)
	// - vector의 동작 원리 (size/capacity)
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	vector<int> v(10);

	// Iterator 없이 순회를 한다고 하면 아래와 같이 순회할 수 있음
	// 그리고 기본적으로 Vector::size()는 unsigned int를 뱉어주기 때문에 warning을 발생시키고 싶지 않다면 #1 또는 #2 방법으로 하면 됨
	
	// #1)
	//for (int i = 0; i < static_cast<signed int>(v.size()); i++)
	//	v[i] = i;
	
	// #2)
	for (vector<int>::size_type i = 0; i < v.size(); i++)
		v[i] = i;

	// ---------------------------------------------------------------

	// 반복자(Iterator) : 포인터와 유사한 개념, 컨테이너의 원소(데이터)를 가리키고, 다음/이전 원소로 이동 가능

	vector<int>::iterator it;	// Iterator
	int* ptr;

	it = v.begin();
	ptr = &v[0];

	cout << *it << endl;
	cout << *ptr << endl;

	cout << "-----------------------------------" << endl;

	it++;
	++it;
	it--;
	--it;

	ptr++;
	++ptr;
	ptr--;
	--ptr;

	it += 2;
	it = it - 2;
	ptr += 2;
	ptr = ptr - 2;

	vector<int>::iterator itBegin = v.begin();	// 첫번째 원소를 가리키고 있음
	vector<int>::iterator itEnd = v.end();		// 유효한 범위 바로 다음 주소를 가리키고 있음. 즉, 쓰레기값이 들어있음

	// ++it가 it++보다 미세하게나마 성능이 더 좋음. Iterator에서 후위연산자는 불필요한 복사가 발생하는 코드가 한줄이 더 있기 때문에 미약한 성능 차이가 있음
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << endl;
	}

	// 더 복잡해보이는데...?
	// 다른 컨테이너는 v[i]와 같은 인덱스 접근이 안될 수도 있음
	// iterator는 vector 뿐만 아니라, 다른 컨테이너에도 공통적으로 있는 개념

	cout << "-----------------------------------" << endl;

	int* ptrBegin = &v[0];
	int* ptrEnd = ptrBegin + 10;

	for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr)
	{
		cout << *ptr << endl;
	}

	// ---------------------------------------------------------------

	// 읽기 전용 iterator
	vector<int>::const_iterator cit = v.cbegin();
	// *cit = 100;	// 불가

	cout << "-----------------------------------" << endl;

	// 역방향 iterator
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << *it << endl;
	}

	return 0;
}