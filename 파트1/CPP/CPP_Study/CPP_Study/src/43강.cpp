#include <iostream>
using namespace std;

// 오늘의 주제 : 로또 번호 생성기

void Swap(int& a, int& b);

void Sort(int numbers[], int count);

void ChooseLotto(int numbers[]);

int main()
{
	// 1) Swap 함수 만들기
	int a = 1;
	int b = 2;
	Swap(a, b);

	cout << a << " " << b << endl;

	// 2) 정렬 함수 만들기 (작은 숫자가 먼저 오도록 정렬)
	int numbers[] = { 1, 42, 3, 15, 5, 6 };
	int count = sizeof(numbers) / sizeof(int);

	for (int i = 0; i < count; i++)
		cout << numbers[i] << " ";
	cout << endl;

	Sort(numbers, count);

	for (int i = 0; i < count; i++)
		cout << numbers[i] << " ";
	cout << endl;

	// 3) 로또 번호 생성기
	ChooseLotto(numbers);

	for (int i = 0; i < count; i++)
		cout << numbers[i] << " ";
	cout << endl;

	return 0;
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Sort(int numbers[], int count)
{
	// 버블 정렬
	//for (int i = 0; i < count - 1; i++)
	//	for (int j = 0; j < count -i - 1; j++)
	//		if (numbers[j] > numbers[j + 1])
	//			Swap(numbers[j], numbers[j + 1]);

	for (int i = 0; i < count; i++)
	{
		// i번째 값이 제일 좋은 후보라고 가정
		int best = i;

		for (int j = i + 1; j < count; j++)
		{
			if (numbers[j] < numbers[best])
				best = j;
		}

		Swap(numbers[i], numbers[best]);
	}
}

void ChooseLotto(int numbers[])
{
	srand((unsigned)time(0));	// 랜덤 시드 설정

	int count = 0;

	// 서로 다른 수 6개 뽑을 때까지 반복
	while (count != 6)
	{
		int randValue = 1 + (rand() % 45);	// 1 + (0 ~ 44)

		bool found = false;	// 중복값 체크를 위한 Flag

		// 이미 뽑은 수 중에 방금 뽑은 수와 중복되는 수가 있는지 체크
		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == randValue)
				found = true;
		}

		// 없다면 numbers에 삽입 후 count++
		if (found == false)
		{
			numbers[count] = randValue;
			count++;
		}
	}

	Sort(numbers, 6);
}