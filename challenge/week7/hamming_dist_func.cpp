#include<iostream>
#include<string>
using namespace std;
//세 개의 함수를 선언
string toLowerStr(string str);
string toUpperStr(string str);
int clacHammingDist(string s1, string s2);

int main()
{
	string s1, s2;//구문 입력 받기 위한 스트링 선언
	int count = 0;
	//구문 입력 받음
	cout << "DNA1 : ";
	cin >> s1;
	cout << "DNA2 : ";
	cin >> s2;

	
	if (s1.length() != s2.length())//서로 길이가 다를 경우
	{
		cout << "오류: 길이가 다름" << endl;
	}
	else// 그 외의 경우
	{
		int count = clacHammingDist(s1, s2);
		cout << "해밍거리는" << count << endl;
	}
	return 0;
}

string toLowerStr(string str)
{
	string cop = str;//str을 받을 변수를 선언 및 초기화
	for (char& a : cop)//cop에 대한 모든 스트링을 확인
	{
		a = tolower(a);//각 인덱스에 들어간 문자를 소문자로 만듬
	}
	return cop;//이렇게 변환된 cop를 출력
}
//위와 같은원리
string toUpperStr(string str)
{
	string cop = str;
	for (char& a : cop)
	{
		a = toupper(a);
	}
	return cop;
}

int clacHammingDist(string s1, string s2)
{
	int count=0;
	string a=toLowerStr(s1);//a와 b를 둘다 소문자로 만든 스트링을 새 변수에 받음
	string b=toLowerStr(s2);
	for (int i = 0; i < s1.length(); i++)// 두 스트링의 길이만큼 반복
	{
		if (a[i] != b[i])//각 인덱스가 다르면 실행
		{
			count += 1;
		}
	}
	return count;//그 횟수를 반복
}