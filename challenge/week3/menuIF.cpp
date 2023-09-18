#include <iostream>
using namespace std;

int main()
{
	int choice;//if문에 들어갈 변수 선언
	//아래는 선택 가능한 화면 출력
	cout << "1. 파일 저장" << endl;
	cout << "2. 저장 없이 닫기" << endl;
	cout << "3. 종료" << endl;
	cin >> choice;//choice에 변수 입력

	if (choice == 1)//입력된 값이 괄호 안과 같을때 true
		cout << "파일 저장을 선택했습니다." << endl;
	else if (choice == 2)//입력된 값이 괄호 안과 같을때 true
		cout << "파일 닫기를 선택했습니다." << endl;
	else if (choice == 3)//입력된 값이 괄호 안과 같을때 true
		cout << "프로그램을 종료합니다." << endl;
	else//choice가 그 외의 나머지 경우일 때
		cout << "잘못된 선택입니다." << endl;
	return 0;//break 필요 없다
}