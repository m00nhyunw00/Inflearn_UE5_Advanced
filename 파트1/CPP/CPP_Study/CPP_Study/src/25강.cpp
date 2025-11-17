#include <iostream>
using namespace std;

int main() {
	// 구구단
	// 2단부터 9단까지 출력해주세요!

	for (int i = 2; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << i << " X " << j << " = " << i * j << endl;
		}
	}
}

//int main() {
//	// 별찍기 3)
//	// 모양이 많이 개선되긴 했는데..
//	// N개부터 시작해서 줄마다 1개씩 줄어드는 형태로!
//
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n - i; j++) {
//			cout << "*";
//		}
//		cout << endl;
//	}
//}

//int main() {
//	// 별찍개 2)
//	// 음.. 구멍 N*N개의 별을 찍으니까 너무 심심하다...
//	// 1개부터 시작해서 순차적으로 줄마다 증가하게 수정해주세요!
//
//	int n;
//	cin >> n;
//
//	for (int i=0; i < n; i++) {
//		for (int j = 0; j <= i; j++) {
//			cout << "*";
//		}
//		cout << endl;
//	}
//}

//int main() {
//	// 별찍기 1)
//	// 유저들이 어떤 정수를 입력하면
//	// N*N개의 별을 찍었으면 좋겠어요!
//
//	//int n;
//	//cin >> n;
//
//	//for (int i = 0; i < n; i++) {
//	//	for (int j = 0; j < n; j++) {
//	//		cout << "*";
//	//	}
//	//	cout << endl;
//	//}
// 
//}



