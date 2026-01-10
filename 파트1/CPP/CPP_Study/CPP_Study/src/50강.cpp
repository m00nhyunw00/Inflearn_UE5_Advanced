#include <iostream>
#include <iomanip>
using namespace std;

// 오늘의 주제 : 연습 문제 (달팽이)

const int MAX = 100;
int board[MAX][MAX] = {};

int N;

void PrintBoard();

void SetBoard_1();	// 내가 작성한 코드
void top(int cycle, int& num);
void right(int cycle, int& num);
void bottom(int cycle, int& num);
void left(int cycle, int& num);

void SetBoard_2();	// 강사님 코드
bool CanGo(int y, int x);

void SetBoard_3();	// 강사님 업그레이드 코드
void SetBoard_4();	// 강사님 업그레이드 코드

enum DIR
{
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3,
};

int main()
{
	cin >> N;

	SetBoard_3();

	PrintBoard();

	return 0;
}

void PrintBoard()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

void SetBoard_1()
{
	int num = 1;

	for (int i = 0; i < N / 2; i++)
	{
		top(i, num);
		right(i, num);
		bottom(i, num);
		left(i, num);
	}

	if (N % 2 == 1)
		board[N / 2][N / 2] = num;
}

void top(int cycle, int& num)
{
	for (int i = 0; i < N - 1 - (cycle * 2); i++)
		board[cycle][cycle + i] = num++;
}

void right(int cycle, int& num)
{
	for (int i = 0; i < N - (cycle * 2) - 1; i++)
		board[cycle + i][N - cycle - 1] = num++;
}

void bottom(int cycle, int& num)
{
	for (int i = 0; i < N - (cycle * 2) - 1; i++)
		board[N - cycle - 1][N - cycle - 1 - i] = num++;
}

void left(int cycle, int& num)
{
	for (int i = 0; i < N - (cycle * 2) - 1; i++)
		board[N - cycle - 1 - i][cycle] = num++;
}

void SetBoard_2()
{
	int dir = RIGHT;

	int num = 1;
	int y = 0;
	int x = 0;

	while (true)
	{
		board[y][x] = num;

		if (num == N * N)
			break;

		int nextY;
		int nextX;

		switch (dir)
		{
		case RIGHT:
			nextY = y;
			nextX = x + 1;
			break;
		case DOWN:
			nextY = y + 1;
			nextX = x;
			break;		
		case LEFT:
			nextY = y;
			nextX = x - 1;
			break;
		case UP:
			nextY = y - 1;
			nextX = x;
			break;
		}

		if (CanGo(nextY, nextX))
		{
			y = nextY;
			x = nextX;
			num++;
		}
		else
		{
			switch (dir)
			{
			case RIGHT:
				dir = DOWN;
				break;
			case DOWN:
				dir = LEFT;
				break;
			case LEFT:
				dir = UP;
				break;
			case UP:
				dir = RIGHT;
				break;
			}
		}
	}
}

void SetBoard_3()
{
	int dir = RIGHT;

	int num = 1;
	int y = 0;
	int x = 0;

	int dy[] = { 0, 1, 0, -1 };
	int dx[] = { 1, 0, -1, 0 };

	while (true)
	{
		board[y][x] = num;

		if (num == N * N)
			break;

		int nextY = y + dy[dir];
		int nextX = x + dx[dir];

		if (CanGo(nextY, nextX))
		{
			y = nextY;
			x = nextX;
			num++;
		}
		else
		{
			switch (dir)
			{
			case RIGHT:
				dir = DOWN;
				break;
			case DOWN:
				dir = LEFT;
				break;
			case LEFT:
				dir = UP;
				break;
			case UP:
				dir = RIGHT;
				break;
			}
		}
	}
}

void SetBoard_4()
{
	int dir = RIGHT;

	int num = 1;
	int y = 0;
	int x = 0;

	int dy[] = { 0, 1, 0, -1 };
	int dx[] = { 1, 0, -1, 0 };

	while (true)
	{
		board[y][x] = num;

		if (num == N * N)
			break;

		int nextY = dy[dir];
		int nextX = dx[dir];

		if (CanGo(nextY, nextX))
		{
			y = nextY;
			x = nextX;
			num++;
		}
		else
			dir = (dir + 1) % 4;
	}
}

bool CanGo(int y, int x)
{
	if (y < 0 || y >= N)
		return false;

	if (x < 0 || x >= N)
		return false;

	if (board[y][x] != 0)
		return false;

	return true;
}
