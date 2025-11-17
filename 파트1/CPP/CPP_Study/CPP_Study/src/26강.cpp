#include <iostream>
using namespace std;

const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;

// 연습 문제 2 : 연습 문제 1 + 승률 계산
int main() {

	int input;
	int ai;
	int count = 0;
	int win = 0;

	srand(time(0));	// 시드 설정

	while (true) 
	{	
		cout << "가위(1) 바위(2) 보(3) 골라주세요!" << endl;
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

// 연습 문제 1 : 랜덤한 패를 내는 컴퓨터와 가위바위보 
//int main() {
//	cout << "가위(1) 바위(2) 보(3) 골라주세요!" << endl;
//
//	const int SCISSORS = 1;
//	const int ROCK = 2;
//	const int PAPER = 3;
//
//	int input;
//	int ai;
//
//	srand(time(0));	// 시드 설정
//
//	while (true)
//	{
//		ai = rand() % 3 + 1; // 1~3 랜덤 숫자 생성
//
//		cin >> input;
//
//		if (input == SCISSORS)
//		{
//			switch (ai)
//			{
//			case SCISSORS:
//				cout << "가위(님) vs 가위(컴퓨터) 비겼습니다!" << endl;
//				break;
//			case ROCK:
//				cout << "가위(님) vs 바위(컴퓨터) 졌습니다!" << endl;
//				break;
//			case PAPER:
//				cout << "가위(님) vs 보(컴퓨터) 이겼습니다!" << endl;
//				break;
//			}
//		}
//		else if (input == ROCK)
//		{
//			switch (ai)
//			{
//			case SCISSORS:
//				cout << "바위(님) vs 가위(컴퓨터) 이겼습니다!" << endl;
//				break;
//			case ROCK:
//				cout << "바위(님) vs 바위(컴퓨터) 비겼습니다!" << endl;
//				break;
//			case PAPER:
//				cout << "바위(님) vs 보(컴퓨터) 졌습니다!" << endl;
//				break;
//			}
//		}
//		else if (input == PAPER)
//		{
//			switch (ai)
//			{
//			case SCISSORS:
//				cout << "보(님) vs 가위(컴퓨터) 졌습니다!" << endl;
//				break;
//			case ROCK:
//				cout << "보(님) vs 바위(컴퓨터) 이겼습니다!" << endl;
//				break;
//			case PAPER:
//				cout << "보(님) vs 보(컴퓨터) 비겼습니다!" << endl;
//				break;
//			}
//		}
//		else
//			break;
//	}
//}