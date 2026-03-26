#include "pch.h"
#include "ConsoleHelper.h"

int main()
{
	uint64 lastTick = 0;
	while (true)
	{
#pragma region 프레임 관리
		// 가변 프레임 방식
		const uint64 currentTick = ::GetTickCount64();
		const uint64 deltaTick = currentTick - lastTick;
		lastTick = currentTick;
#pragma endregion 

		// 입력

		// 로직

		// 렌더링

	}
}