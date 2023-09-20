#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str = "The Jin state was formed in southern Korea";
	char find = 'a';
	int size = str.size();//반복문의 조건문에 넣어주기 위해서 스트링의 크기를 변수에 할당
	int count = 0;

	for (int i = 0; i < size; i++)//문자열은 0부터 시작해서 문자열의 개수와 반복횟수가 같도록 조건문 설정.
	{
		if (str[i] == find)//반복문을 문자의 수만큼 하는 와중에 a인 문자가 문자열의 그 칸에 한달되어있으면 count를 증가
			count++;
	}

	cout << "문장의 a 개수는" << count << "개 입니다." << endl;
	return 0;
}