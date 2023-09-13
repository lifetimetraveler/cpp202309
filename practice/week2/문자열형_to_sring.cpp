#include <iostream>
#include<string>
using namespace std;

int main()
{
	string s1 = "사과";
	string s2;
	s2 = s1 + " " + to_string(10) + "개";//to_string을 쓰지 않으면 10이라는 것은 int형이여서 에러가 발생.
	//s2=s1+""+10+"개"  to_string이 다른 자료형도 string에 통합시켜준다.
		cout << s2 << endl;
	return 0;
}