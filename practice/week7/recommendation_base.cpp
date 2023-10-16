#include <iostream>
using namespace std;

int main() {
	const int NUM_USERS = 3;
	const int NUM_ITEMS = 3;
	int userPreferences[NUM_USERS][NUM_ITEMS];

	//각 사용자를 출력하고 입력 받을 개수를 출력
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (";
		cout << NUM_ITEMS << "개의 항목에 대해 ):";
	for (int j = 0; j < NUM_ITEMS; ++j)
		{
			cin >> userPreferences[i][j];
		}
	}

	//사용자 추천 항목 설정
	for (int i = 0; i < NUM_USERS; ++i) {//사용자 수만큼 반복 및 최대선호 항목을 위한 변수
		int maxPreferenceIndex = 0;
		for (int j = 1; j < NUM_ITEMS; ++j)//항목의 수-1 만큼 반복, 가장 처음은 맥스프리퍼런스가 0이여서 한번 적게해도 됨.
		{
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex])//선호도가 더 높은 값을 만나면
			{
				maxPreferenceIndex = j;//그 사용자의 그때의 인덱스 값을 저장
			}
		}


		// 사용자의 선호 항목을 출력
		cout << "사용자 " << (i + 1) << "에게 추천하는 항목: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}
	return 0;
}