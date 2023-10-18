#include<iostream>
#include<string>
using namespace std;

int main()
{//스트링 입력을 위한 변수
	string s1, s2;
	int count = 0;//해밍거리를 받기위한 변수
	//구문 입력
	cout << "DNA1 : ";
	cin >> s1;
	cout << "DNA2 : ";
	cin >> s2;


	if (s1.length() != s2.length())//스트링의 길이가 다르면
	{
		cout << "오류: 길이가 다름" << endl;//출력
	}
	else
	{//두 배열(스트링)의 길이만큼 반복
		for(int i=0;i<s1.length();i++)
		{
			if (s1[i] != s2[i])//모든 배열을 확인 하다가 다르면
			{
				count += 1;//카운트를 올림
			}
			
		}
		cout << "해밍거리는" << count << endl;//카운트를 출력
	}
	return 0;
}