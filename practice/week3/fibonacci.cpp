#include<iostream>
using namespace std;

int main()
{
	int p = 0;//변수 세개 선언 및 초기화
	int n = 0;
	int t = 0;

	for (int i = 1; i < 10; i++)//1~9까지 반복
	{
		p = 0;//반복이 될 때마다 두 변수는 각각 0과 1로 초기화.
		n = 1;

		for (int j = 1; j <= i; j++)//위의 for 문이 한 번 실행하면 이 for문이 1~i의 값 까지 반복
		{
			cout << n << ", ";//

			t = n; //n은 항상 1로 다시 한단계 밖의 for문을 반복하면서 초기화 되어서 t는 1부터 시작
			n += p;//n에 p가 더해져서 n을 초기화
			p = t;
		}
		cout << endl;
	}
	return 0;
}