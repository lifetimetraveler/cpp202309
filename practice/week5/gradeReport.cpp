#include<iostream>
#include<string>
using namespace std;

int main()
{
	const int STUDENT = 5;//학생수를 상수로 선언
	const int SUBJECT = 3;//과목 수를 상수로 선언
	int scores[STUDENT][SUBJECT];//학생아래에 과목을 갖는 2차 배열 선언, 여기에 점수를 받음
	string studentNames[STUDENT]//학생 수 만큼 배열 생성,학생의 이름 선언,초기화
		= { "영수", "영희", "철수", "미미", "주주" };
	string subjectNames[SUBJECT] =//과목 수 만큼 배열 선언,과목의 이름, 초기화
	{ "수학","영어","cpp" };

	for (int i = 0; i < STUDENT; i++)//학생 수 만큼 아래 지시문 반복
	{
		cout << studentNames[i]//먼저 학생이름을 제시해주고 구문을 출력
			<< "의 성적을 하나씩 입력하세요." << endl;
		for (int j = 0; j < SUBJECT; j++)//한 학생의 이름이 나오면 과목 수만큼 반복
		{
			cout << subjectNames[j] << ":";//과목 이름 제시
			cin >> scores[i][j];//과목에 맞는 성적 입력 받음
		}
	}

	for (int i = 0; i < STUDENT; i++)//학생 수 만큼 아래 반복
	{
		cout << studentNames[i] << "의 평균 점수는";//그 배열에 맞는 학생 출력
		double sum = 0;
		double average = 0;
		for (int j = 0; j < SUBJECT; j++)// 그 학생의 과목 마다 점수를 불러와서 평균을 냄
		{
			sum += scores[i][j];
		}
		average = sum / SUBJECT;//이렇게 새롭게 초기화된 sum의 값을 average에 할당
		cout << average << "입니다." << endl;//초기화된 average의 값을 출력
	}
	return 0;
}