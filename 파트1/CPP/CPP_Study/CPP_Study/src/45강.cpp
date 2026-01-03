#include <iostream>
using namespace std;

// 오늘의 주제 : 다차원 배열

int main()
{
	int a[10] = { 1,2,3 };	

	// [1] [1] [5] [2] [2] << 1층
	// [4] [2] [3] [4] [1] << 0층

	int first[5] = { 4,2,3,4,1 };
	int second[5] = { 1,1,5,2,2 };

	// 층수가 높아지면 배열을 각각 만들기가 힘들다...
	// -> 다차원 배열!

	int apartment2D[2][5] = { { 4,2,3,4,1 }, { 1,1,5,2,2 } };	// 위 상황을 2차원 배열로 표현하면 다음과 같다.

	for (int floor = 0; floor < 2; floor++)
	{
		for (int room = 0; room < 5; room++)
		{
			int num = apartment2D[floor][room];
			cout << num << " ";
		}
		cout << endl;
	}

	int apartment1D[10] = { 4,2,3,4,1,1,1,5,2,2 };

	for (int floor = 0; floor < 2; floor++)
	{
		for (int room = 0; room < 5; room++)
		{
			int index = (floor * 5) + room;
			int num = apartment2D[floor][room];
			cout << num << " ";
		}
		cout << endl;
	}

	// 2차원 배열은 언제 사용할까? 대표적으로 2D 로그라이크 맵

	int map[5][5] =
	{
		{1,1,1,1,1},
		{1,0,0,1,1},
		{0,0,0,0,1},
		{1,0,0,0,0},
		{1,1,1,1,1}
	};

	return 0;
}