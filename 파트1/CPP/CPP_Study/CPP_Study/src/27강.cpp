#include <iostream>
using namespace std;

// 초기값 지정 안하면 첫 값은 0부터 시작
// 그 다음 값들은 지정해주지 않으면 이전 값 + 1
// 값은 정수만 가능
enum
{
	ENUM_SCISSORS,	// 0
	ENUM_ROCK,		// 1
	ENUM_PAPER,		// 2, 마지막은 뒤에 콤마 붙여도 되고 안붙여도 됨
};

//enum ENUM_SRP
//{
//	ENUM_SCISSORS = 3,		// 3
//	ENUM_ROCK = 5,			// 5
//	ENUM_PAPER				// 6
//};

// 상수는 반드시 초기값 지정해줘야함
const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;

// 1) 전처리 2) 컴파일 3) 링크
// #이 붙은 것 -> 전처리 지시문
// #include는 뒤에 오는 파일의 내용을 통째로 복붙해달라는 의미
// #define은 뒤에 오는 문구를 지정한 코드로 대체해달라는 의미
#define DEFINE_SCISSORS 1
#define DEFINE_TEST 0.123
#define DEFINE_GUIDE cout << "가위(1) 바위(2) 보(3) 골라주세요!" << endl;
#define DEFINE_TEST_2 1+2

int main() {
	cout << DEFINE_TEST_2 * 2 << endl;

	int input;
	int ai;
	int count = 0;
	int win = 0;

	srand(time(0));	// 시드 설정

	while (true)
	{
		DEFINE_GUIDE;
		cout << "> 현재 승률 : ";

		if (count == 0)
			cout << "없음" << endl;
		else
		{
			int winPercentage = 100 * win / count;
			cout << winPercentage << " %" << endl;
		}

		ai = rand() % 3 + 1; // 1~3 랜덤 숫자 생성

		cin >> input;

		// 사용자가 가위를 냈을 떄
		if (input == SCISSORS)
		{
			switch (ai)
			{
			case SCISSORS:
				cout << "가위(님) vs 가위(컴퓨터) 비겼습니다!" << endl;
				break;
			case ROCK:
				count++;
				cout << "가위(님) vs 바위(컴퓨터) 졌습니다!" << endl;
				break;
			case PAPER:
				count++;
				cout << "가위(님) vs 보(컴퓨터) 이겼습니다!" << endl;
				win++;
				break;
			}
		}
		// 사용자가 가위를 냈을 떄
		else if (input == ROCK)
		{
			switch (ai)
			{
			case SCISSORS:
				count++;
				cout << "바위(님) vs 가위(컴퓨터) 이겼습니다!" << endl;
				win++;
				break;
			case ROCK:
				cout << "바위(님) vs 바위(컴퓨터) 비겼습니다!" << endl;
				break;
			case PAPER:
				count++;
				cout << "바위(님) vs 보(컴퓨터) 졌습니다!" << endl;
				break;
			}
		}
		// 사용자가 가위를 냈을 떄
		else if (input == PAPER)
		{
			count++;

			switch (ai)
			{
			case SCISSORS:
				count++;
				cout << "보(님) vs 가위(컴퓨터) 졌습니다!" << endl;
				break;
			case ROCK:
				count++;
				cout << "보(님) vs 바위(컴퓨터) 이겼습니다!" << endl;
				win++;
				break;
			case PAPER:
				cout << "보(님) vs 보(컴퓨터) 비겼습니다!" << endl;
				break;
			}
		}
		// 사용자가 올바르지 않은 입력을 했을 때 프로그램 종료
		else
			break;

		cout << endl;
	}
}