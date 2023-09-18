#include <iostream>
using namespace std;

int main()
{
	int choice;//switch에 들어갈 변수 선언
	//아래는 선택 가능한 화면 출력
	cout << "1. 파일 저장" << endl;
	cout << "2. 저장 없이 닫기" << endl;
	cout << "3. 종료" << endl;
	cin >> choice;//switch 에 들어갈 변수 입력=메뉴 선택

	switch (choice)//choice 값이 case옆의 값과 같으면 그 아래 문장 실행
	{//실행하다가 break를 만나서 switch 탈출
	case 1:
		cout << "파일 저장을 선택했습니다." << endl;
		break;
	case 2:
		cout << "파일 닫기를 선택했습니다." << endl;
		break;
	case 3:
		cout << "프로그램을 종료합니다." << endl;
		break;
	case 4:
		cout << "잘못된 선택입니다." << endl;
		break;
	}
	return 0;
}