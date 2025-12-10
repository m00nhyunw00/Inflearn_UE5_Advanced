#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 vs 참조

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

void CreateMonster(StatInfo& info)
{
	info.hp = 100;
	info.attack = 8;
	info.defence = 5;
}

StatInfo globalnfo;

void PrintInfoByPtr(StatInfo* info)
{
	if (info == nullptr)
		return;

	cout << info->hp << " " << info->attack << " " << info->defence << endl;

	// * 뒤에 const 붙이는 경우
	// StatInfo* const info
	// - info에 들어있는 주소값 수정 불가
	info = &globalnfo;

	// * 앞에 const 붙이는 경우
	// const Statinfo* info || Statinfo const * info
	// - 주소값에 위치한 변수의 값 수정 불가
	info->hp = 10000;
}

void PrintInfoByRef(const StatInfo& info)
{
	cout << info.hp << " " << info.attack << " " << info.defence << endl;
}

#define OUT
void ChangeInfo(OUT StatInfo& info)
{
	info.hp = 1000;
}

int main()
{
	StatInfo info;
	CreateMonster(info);

	// 포인터 vs 참조
	// 성능 : 똑같음!
	// 편의성 : 참조 승!

	// 1) 편의성 관련
	// 편의성이 좋다는게 꼭 장점만은 아니다.
	// 포인터는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트를 줄 수 있는데,
	// 참조는 자연스럽게 모르고 지나친 수도 있음!

	PrintInfoByPtr(&info);	// 원본을 건드릴 수 있다는 것을 직관적으로 알 수 있음

	PrintInfoByRef(info);	// 참조 전달 방식인지 값 전달 방식인지 알 수 없어 
						// 함수 내부에서 수정하면 안되는 원본의 데이터를 수정할 수도 있음
						// 이럴 때는 const 키워드 활용!

	///////////////////////////////////////////////////////////////

	// 2) 초기화 여부
	// 참조 타입은 바구니의 2번째 이름 (별칭?)
	// -> 참조하는 대상이 없으면 안됨

	StatInfo* pointer = nullptr;
	PrintInfoByPtr(pointer);
	// 위와 같은 경우는 일단 실행은 되지만,
	// 디버깅을 해보면 유효하지 않은 주소를 함수에 넣어서 예외가 발생함
	// 따라서 함수에 예외 처리를 해줘야함

	// StatInfo& reference; 
	// refence = info;
	// 위와 같은 경우는 에러 발생 : 반드시 참조하는 대상이 필요!

	StatInfo& reference = info;
	PrintInfoByRef(reference);

	// 그래서 결론은?
	// 사실 team by team... 정해진 답은 없다
	// ex) 구글에서 만든 오픈 소스를 보면 거의 무조건 포인터 사용
	// ex) 언리얼 엔진에서는 reference도 애용

	// 강사님의 추천 방식은
	// - 없는 경우도 고려해야 한다면 pointer(NULL 체크 필수)
	// - 바뀌지 않고 읽는 용도(readonly)만 사용한다면 const& ref
	// - 그  외 일반적으로 ref(명시적으로 호출할 때 OUT을 붙인다)
	ChangeInfo(OUT info);

	// Bonus) 포인터로 사용하던걸 참조로 넘겨주려면?
	pointer = &info;
	// PrintInfoByRef(pointer); // 오류 발생
	PrintInfoByRef(*pointer);

	// Bonus) 참조로 사용하던걸 포인터로 넘겨주려면?
	// PrintInfoByPtr(reference);	// 오류 발생
	PrintInfoByPtr(&reference);

	return 0;
}