#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1 = "good";//string 형 변수 두개를 선언과 동시에 초기화
	string s2 = "morning";
	string s3 = s1 + " " + s2 + "!";
	cout << s3 << endl;//s3를 출력
	return 0;

}