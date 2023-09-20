#include <iostream>

using namespace std;

int main()
{
	int vowe1 =0;
	int consonant = 0;
	cout << "영문자를 입력하고 ctrl+z를 치세요" << endl;

	char ch;
	
	while (cin>>ch) {//문자를 입력 받고 그에 ch에 할당, true를 넣는 역할도 함.
		switch (ch)
		{//각 알파벳이 나왔을때 모음이면 vowe의 값을 올리고 자음이면 consonant를 1씩 올림.
		case 'a':
			vowe1++;
			break;
		case 'b':
			consonant++;
			break;
		case 'c':
			consonant++;
			break;
		case 'd':
			consonant++;
			break;
		case 'e':
			vowe1++;
			break;
		case 'f':
			consonant++;
			break;
		case 'g':
			consonant++;
			break;
		case 'h':
			consonant++;
			break;
		case 'i':
			vowe1++;
			break;
		case 'j':
			consonant++;
			break;
		case 'k':
			consonant++;
			break;
		case 'l':
			consonant++;
			break;
		case 'm':
			consonant++;
			break;
		case 'n':
			consonant++;
			break;
		case 'o':
			vowe1++;
			break;
		case 'p':
			consonant++;
			break;
		case 'q':
			consonant++;
			break;
		case 'r':
			consonant++;
			break;
		case 's':
			consonant++;
			break;
		case 't':
			consonant++;
			break;
		case 'u':
			vowe1++;
			break;
		case 'v':
			consonant++;
			break;
		case 'w':
			vowe1++;
			break;
		case 'x':
			consonant++;
			break;
		case 'y':
			vowe1++;
			break;
		case 'z':
			consonant++;
			break;

		}
	}
	cout << "모음: " << vowe1 << endl;//컨트롤제트하면 탈출하고 
	cout << "자음: " << consonant << endl;//결과 출력
	return 0;
}