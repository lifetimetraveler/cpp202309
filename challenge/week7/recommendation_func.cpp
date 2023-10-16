#include<iostream>
using namespace std;

const int NUM_USERS = 3;
const int NUM_ITEMS = 3;
int userPrefuerneces[NUM_USERS][NUM_ITEMS];
//사용자 선호도를 입력 받는 함수
void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS])
{
	for (int i = 0; i < NUM_USERS; ++i)//유저 수만큼 반복
	{
		cout << "사용자" << (i + 1) << "의 선호도를 입력하세요 (" << NUM_ITEMS << "개의 항목에 대해): ";
		for (int j = 0; j < NUM_ITEMS; ++j)
		{
			cin >> preferences[i][j];
		}
	}
}
//사용자 별 추천 항목을 찾고 출력하는 함수
void findRecommendeditems(const int preferences[NUM_USERS][NUM_ITEMS])
{
	for (int i = 0; i < NUM_USERS; ++i)
	{
		int maxPreferenceindex = 0;
		for (int j = 1; j < NUM_ITEMS; ++j)//항목의 수-1 만큼 반복, 가장 처음은 맥스프리퍼런스가 0이여서 한번 적게해도 됨.
		{
			if (preferences[i][j] > preferences[i][maxPreferenceindex])//선호도가 더 높은 값을 만나면
			{
				maxPreferenceindex = j;//그 사용자의 그때의 인덱스 값을 저장
			}
		}
		// 사용자의 선호 항목을 출력
		cout << "사용자 " << (i + 1) << "에게 추천하는 항목: ";
		cout << (maxPreferenceindex + 1) << endl;
	}
}
int main() {
	initializePreferences(userPrefuerneces);//각 함수에 전역 변수로 선언한 userPreference를 넣음
	findRecommendeditems(userPrefuerneces);

	return 0;
}