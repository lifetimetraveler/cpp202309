#include<iostream>

using namespace std;

int main()
{
	int userinput;


	
	
	for (int i = 0; i < 10; i++) {//1~09까지 반복
		cin >> userinput;//유저가 입력
		if (userinput == 0)//0이 입력되면 탈출
			break;
		cout << "입력값: " << userinput << "횟수: " << i << endl;//결과 출력
		
	}//이 과정이 반복되서 10번 반복
	cout << "종료 되었습니다.";
	return 0;

}