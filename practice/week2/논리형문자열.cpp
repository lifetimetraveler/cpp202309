#include <iostream>
#include<string>
using namespace std;

int main()
{
	string s1 = "Good";//s1, s2변수 선언과 동시에 초기화
	string s2 = "Bad";
	bool b = (s1 == s2);//s1과 s2가 다르기 때문에 false가 할당
	cout << b << endl;//false여서 0출력

	s2 = "Good";//s2에 good 을 할당해서 s1과 같아짐
	b = (s1 == s2);//s1과 s2가 같아져서 true가 할당된다. 
	cout << b << endl;//true 여서 1출력
	return 0;
}