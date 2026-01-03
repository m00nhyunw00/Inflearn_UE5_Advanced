#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 마무리

// 1) 포인터 vs 배열 2탄
// 2) 주의사랑 (마음가짐?)

int& TestRef()
{
	int a = 1;
	return a;
}

int* TestPtr()
{
	int a = 1;
	return &a;
}

void TestWrong(int* ptr)
{
	int a[100] = {};
	a[99] = 0XAAAAAAAA;
	*ptr = 0X12341234;
}

int main()
{
	// 주소를 담는 바구니
	// 진퉁은 저~ 멀리 어딘가에 있음
	// p는 단지 그곳으로 워프하는 포탈
	int* p;

	// 진짜배기! 원조 데이터
	// 닭장처럼 데이터의 묶음 (엄청 많고 거대함)
	int arr[10] = { 1,2,3,4,5,6,7,8 };

	// 그런데도 상당히 많은 사람들이 [배열 = 포인터]라 착각하는 경향이 있음!

	// - [배열의 이름]은 배열의 시작 주소값을 가리키는 TYPE* 포인터로 변환 가능!
	p = arr;

	// - [TYPE형 1차원 배열]과 [TYPE*형 포인터]는 완전히 호환이 된다
	cout << p << endl;
	cout << arr << endl;
	cout << p[0] << endl;
	cout << arr[0] << endl;
	cout << p[5] << endl;
	cout << arr[5] << endl;
	cout << *p << endl;		// p[0]
	cout << *arr << endl;	// arr[0]
	cout << *(p + 3) << endl;
	cout << *(arr + 3) << endl;

	// 지옥 버전 : 2차원 배열 vs 다중 포인터

	//[1][2][3][4]
	int arr2[2][2] = { {1, 2}, {3, 4} };

	// 주소2[] << 4바이트
	// 주소1[ 주소2 ]
	// pp[ 주소1 ]
	
	// int** pp = arr2;	// 2차원 배열과 이중 포인터는 쉽게는 호환 안됨

	// 아래와 같이 선언하여 사용 가능 (거의 사용할 일 없어서 잊어버려도 됨)
	int(*p2)[2] = arr2;

	cout << (*p2)[0] << endl;
	cout << (*p2)[1] << endl;
	cout << (*(p2 + 1))[0] << endl;
	cout << (*(p2 + 1))[1] << endl;

	cout << p2[0][0] << endl;
	cout << p2[0][1] << endl;
	cout << p2[1][0] << endl;
	cout << p2[1][1] << endl;
	cout << endl;

	int* pointer = TestPtr();
	cout << *pointer << endl;
	*pointer = 123;
	cout << *pointer << endl;
	
	TestWrong(pointer);

	return 0;
}