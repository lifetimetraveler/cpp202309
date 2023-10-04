#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	const int numCell = 10;//numCell을 10으로 상수화
	int numList[numCell][numCell];//numCell의 가로와 세로를 가진 이차원 배열 선언

	for (int i = 0; i < numCell; i++)//각각의 배열에 램던값을 할당
	{
		for (int j = 0; j < numCell; j++)
		{
			numList[i][j] = rand() % 1000;//0~999까지의 값을 할당
		}
	}
	cout << endl;

	int max=0;//큰 값을 넣을 변수 선언
	int maxI;//i를 넣기 위해 선언
	int maxJ;//j를 넣기 위해 선언

	for (int i = 0; i < numCell; i++)
	{
		int b = 0;//배열 내에서 몇번 돌았는지 확인을 위한 변수, 또한 각 i에 들어왔을 때, 0으로 초기화
		for (int j : numList[i]) {
			b++;
			if (j > max)//max에 저장된 값보다 큰 것을 만나면 실행
			{
				max = j;//큰 값을 바꿔줌
				maxI = i;//그 때의 i를 저장
				maxJ = b-1;//b를 올리고 시작하니까 1을 빼줌, if 문 뒤에 b++를 옮겨도 가능
			}
		}

		cout << "가장 큰 값은" << max << "이고,";
		cout << "i와 j는 각각" << maxI << ", " << maxJ << "입니다" << endl;
		cout << "검증 결과: " << numList[maxI][maxJ] << endl;

		return 0;

	}
}