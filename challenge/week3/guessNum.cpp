#include<iostream>
#include<time.h>
using namespace std;

int main() {
	srand(time(NULL));

	int answer = rand() % 100;//랜덤의 수, 정답 생성
	int tries = 0;

	int guess;//사용자가 입력할 수

	do {
		cout << "정답을 추측하여 보시오:";
			cin >> guess; //사용자의 입력
		tries++;//한번 할때마다 횟수가 1씩 올라가도록

		if (guess > answer)//추측이 높으면 아래문장 출력
			cout << "제시한 정수가 높습니다" << endl;
		if (guess < answer)//추측이낮으면 아래문장 출력
			cout << "제시한 정수가 낮습니다" << endl;
	} while (guess != answer);//정답과 추측이 같아지면 0false가 나오도록
	cout << "축하합니다. 시도 횟수=" << tries << endl;
	return 0;
	
}