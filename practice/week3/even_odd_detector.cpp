#include<iostream>
using namespace std;

int main() {
	int data[5] = { 5, 19,76,3,10 };
	for (int i = 0; i < 5; i++)//0~4까지 갈때까지 반복. 
	{
		if (data[i] % 2 == 0)//2로 나뉘어 떨어질 때만 아래의 짝수입니다가 출력
			cout << i << ":" << data[i] << "는 짝수입니다." << endl;
		else//그 외의 경우인 홀수일 때 아래 문장 출력.
			cout << i << ":" << data[i] << "는 홀수입니다." << endl;
	}
	return 0;
}