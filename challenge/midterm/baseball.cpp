#include <iostream>
#include <string>
using namespace std;


//중복되는 숫자를 확인하기 위한 함수 선언
bool checkNumber(int userNumber);

int main() {
	int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
	char firstNum; // 정답의 첫번째 자리수
	char secondNum; // 정답의 두번째 자리수
	char thirdNum; // 정답의 세번째 자리수

	while (1) {
		randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성

		bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

		// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성

		string num = to_string(randomNum);//무작위 수를 string에 넣는다.
		firstNum = num[0];//string 배열의 각 숫자가 char형의 변수에 담긴다. 각 자리수에 할당하는 과정
		secondNum = num[1];
		thirdNum = num[2];

		//함수를 사용하여 중복되는지 확인
		same = checkNumber(randomNum);//중복없다면 함수가 true를 저장. 있으면 false저장.

		if(same==false)//중복이 있는 경우. 무한 루프 복귀.
		{
			continue;
		}
		if (same == true) {//중복이 없으면 탈출
			break;
		}

	}

	int turn = 0;//반복 횟수를 확인하기 위한 변수 선언 및 초기화
	while (1)
	{
		//시도 횟수의 출력
		cout << turn + 1 << "번째 시도입니다. " << endl;

		int userNumber; // 사용자가 입력한 세자리수 저장 변수
		char guessFirst; // 추측한 숫자의 첫번째 자리수
		char guessSecond; // 추측한 숫자의 두번째 자리수
		char guessThird; // 추측한 숫자의 세번째 자리수


		// 사용자에게 세자리 수를 입력받는 코드 블록
		while (1) {
			cout << "세자리 수를 입력해주세요: ";
			cin >> userNumber;

			bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
			// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성

			//세 자리 수를 추출하기 위해 string에 저장
			string check = to_string(userNumber);

			//check string이 길이가 3이 아니면(3 자리수가 아니면) 앞으로 복귀
			if (check.length() != 3) {
				cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
				continue;
			}

			//각 자리수를 string에서 char에 저장
			guessFirst = check[0];
			guessSecond = check[1];
			guessThird = check[2];

			//함수를 사용하여 중복되는지 확인
			same = checkNumber(userNumber);//중복없다면 함수가 true를 저장. 있으면 false저장.



			if (same == false)//중복이 있는 경우. 관련 메세지 출력
			{
				cout << "입력한 숫자에 중복된 숫자가 있습니다. 다시 입력하세요." << endl;
			}
			//중복이 없다면 탈출
			if (same == true) {
				break;
			}
		}


		int strike = 0; // 스트라이크 갯수를 저장하는 변수
		int ball = 0; // 볼 갯수를 저장하는 변수

		// TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성
		
		
		//입력한 수와 랜덤 생성된 수와 자리수와 숫자가 동일하다면
		//strike에 1 가산.
		if (guessFirst == firstNum)
		{
			strike++;
		}
		if (guessSecond == secondNum)
		{
			strike++;
		}
		if (guessThird == thirdNum)
		{
			strike++;
		}

		//입력한 수와 랜덤 수가 숫자는 일치하나 다른 자릿수인 경우
		//ball++
		if (guessFirst == secondNum || guessFirst == thirdNum)
		{
			ball++;
		}
		if (guessSecond == firstNum || guessSecond == thirdNum)
		{
			ball++;
		}
		if (guessThird == firstNum || guessThird == secondNum)
		{
			ball++;
		}


		//힌트를 출력
		cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;

		//strike가 3 개인 경우는 완전히 맞춘것이기 때문에 정답 출력
		if (strike == 3) {
			cout << "정답을 맞췄습니다. 축하합니다."<<endl;
			break;
		}
		//맞춘 것이 없다면 아웃을 출력
		if (strike + ball == 0)
		{
			cout << "아웃입니다."<<endl;
		}


		turn += 1;//횟수를 가산
	}

	return 0;
}

//입력받은 수의 자리 수가 중복되는 지 확인하는 함수
//중복이 있다면 false를 출력하고 없다면 true를 출력한다.
bool checkNumber(int userNumber)
{
	string check = to_string(userNumber);//string 배열에 저장하여 자리수의 중복을 확인한다.
	if (check[0] == check[1] || check[1] == check[2] || check[0] == check[2])
	{
	
		return false;
	}
	return true;
}