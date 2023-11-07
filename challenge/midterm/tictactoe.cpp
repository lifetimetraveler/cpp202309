#include <iostream>
using namespace std;
const int numCell = 3; // 보드판의 가로 세로 길이

//입력받은 좌표의 타당성을 검증하는 함수.
bool isValid(int x, int y, char board[][numCell]);
//승자 체크코드 함수
bool checkWin(char board[][numCell], char currentUser);

int main() {
	// 게임을 진행하는 데 필요한 변수 선언
	const int USERNUM = 3;
	const int numCell = 3; // 보드판의 가로 세로 길이
	int k = 0; // 누구 차례인지 체크하기 위한 변수
	char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수
	char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열
	int x, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수

	// 보드판 초기화
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// 게임을 무한 반복
	while (true) {
		// 1. 누구 차례인지 출력
		// TODO 1.1: 3인용 게임으로 변경
		switch (k % USERNUM) {//반복횟수를 유저수로 나눠 나머지에 따라 현재 유저를 설정
		case 0:
			currentUser = 'X';
			break;
		case 1:
			currentUser = 'O';
			break;
		case 2:
			currentUser = 'H';
			break;
		}
		//어떤 유저의 순서인지 출력
		cout << k % USERNUM + 1 << "번 유저(" << currentUser << ")의 차례입니다. -> ";

		// 2. 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요: ";
		int x, y;
		cin >> x >> y;

		// 3. 입력받은 좌표의 유효성 체크
		// TODO FUNC 1: isValid 함수 생성 후 호출
		
		//유효하지 않으면(함수가 false를 반환) 무한 루프 복귀
		if (isValid(x, y,board)==false)
		{
			continue;
		}//true라면 다음 코드로 진행



		// 4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		// 5. 현재 보드 판 출력
		// TODO 1.2: numCell 숫자에 맞춘 보드판 출력
		for (int i = 0; i < numCell; i++) 
		{
			//각 y축에 들어갈 때마다 가장 앞에서 실행하여 위 천장이 된다.
			for (int k = 0; k < numCell - 1; k++)//보드판보다 하나 적게 반복하고
			{
				cout << "---|";

			}cout << "---\n";//마지막 한번은 이것으로 채운다.

			for (int j = 0; j < numCell; j++)//각 y축에 진입하여 x축의 값과 옆 칸막이를 차례로 출력.
			{
				cout << " " << board[i][j] << " ";
			
				if (j == numCell - 1) {//마지막에서는 칸막이를 덮지 않는다.
					break;
				}
				cout<< "|";//칸막이 역할
			}
			cout << endl;
		}
		//가장 마지막에 출력하여 맨 밑바닥을 막는 뚜껑
		for (int k = 0; k < numCell - 1; k++)//보드판 보다 한번 적게 실행하고
		{
			cout << "---|";

		}cout << "---\n";//그 마지막에 덮어준다.



		bool isWin = false;
		isWin = checkWin(board,currentUser);// 승리 여부를 저장. 
		// TODO FUNC2: 6.1부터 6.2까지 checkWin 함수 생성 후 호출
		



		// 승리자가 결정되었으면 해당 플레이어를 출력하고 게임을 종료한다.
		if (isWin == true) {//승리된 값에 따라 승리자와 메세지 출력.
			cout << k % USERNUM + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			break;
		}

		// 7. 모든 칸 다 찼는지 체크하기
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {//모든 배열을 탐색하고 공란이 있다면 checked를 올림
					checked++;//즉, 공란의 수가 checked에 저장된 수.
				}
			}
		}
		if (checked == 0) {//checked가 0이면, 공란이 없다면 종료
			cout << "모든 칸이 다 찼습니다.  종료합니다. " << endl;
			break;
		}

		k++;//횟수를 올린다.
	}

	return 0;
}

//입력받은 좌표의 타당성을 검증하는 함수. 올바른 좌표면 true를 출력, 아니면 false를 출력.
bool isValid(int x, int y, char board[][numCell])
{
	if (x >= numCell || y >= numCell) {// 좌표 범위를 벗어날때
		cout << x << "," << y << ": x와 y둘중 하나가 칸을 벗어납니다. " << endl;
		return false;
	}
	if (board[x][y] != ' ') {// 좌표범위의 입력값이 중복될때. 좌표가 공란이 아닌경우
		cout << x << "," << y << ": 이미 돌이 차있습니다. " << endl;
		return false;
	}
	return true;
}

//승리 코드체크를 위한 함수. 승리 조건이 충족되면 true를 반환. 어떠한 조건도 못 맞추면 끝에 false를 반환.
bool checkWin(char board[][numCell], char currentUser)
{
	// 6.1. 가로/세로 돌 체크하기
	for (int i = 0; i < numCell; i++) {//각 y축 위의 값을 모두 확인하여 모두 같다면 true를 반환
		if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
			cout << "가로에 모두 돌이 놓였습니다!!";
			return true;
			break;
		}
		//각 x축 위의 값들을 모두 확인하여 모두 같다면 true를 반환
		if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
			cout << "세로에 모두 돌이 놓였습니다!!";
			return true;
			break;
		}
	}
	// 6.2. 대각선을 체크하기
	// TODO 1.3: numCell에 맞춘 대각선 빙고 체크 코드로 확장
	// HINT: for 문

	//기본적으로 모든 배열을 확인하여 전방과 후방의 변수값이 같은지를 확인한다.
	//board의 칸 수보다 1번 적게 실행하며, 배열의 전후방 값을 확인한다.
	//board의 칸 수-1까지 확인할 때까지 전후방의 값이 연속적으로 같다면(한user라면) 빙고가 완성된 것이다.

	//좌상부터 우하단 대각선을 확인
	int bc = 0;//일치횟수를 체크하기 위한 변수

	for (int i = 0; i < numCell - 1; i++)//대각선에서 승리를 위해 필요한 칸의 수는 board의 크기와 같다.
	{//따라서 board의 크기-1만큼 전후방의 배열이 같은지 확인한다.
		if (board[i][i] == board[i + 1][i + 1] && board[i][i] != ' ' && board[i + 1][i + 1] != ' ')
		{//board의 전방과 후방이 공란이 아니고, 그 값이 같다면 일치횟수를 가산
			bc++;//후방의 배열은 [전방+1][전방+1]
		}

	}

	if (bc == numCell - 1)//일치 횟수가 for문의 반복횟수와 같다면 true를 반환.
	{
		cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!";
		return true;
	}

	//좌하단부터 우상단을 확인
	int bd = 0;//일치횟수를 체크하기 위한 변수
	for (int i = 0; i < numCell - 1; i++)//대각선에서 승리를 위해 필요한 칸의 수는 board의 크기와 같다.
	{
		if (board[numCell - 1 - i][i] != ' ' && board[numCell - 2 - i][i + 1] != ' ')
		{//전후방이 공란이 아니고
			if (board[numCell - 1 - i][i] == board[numCell - 2 - i][i + 1])
			{//전후방의 값이 같다면 횟수를 가산
				bd++;//후방의 배열은 [전방-1][전방+1]
			}
		}
	}
	if (bd == numCell - 1)//일치 횟수가 for문의 반복횟수와 같다면 true를 반환.
	{
		cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!";
		return true;
	}
	return false;//앞의 모든 조건이 실패하면 false를 반환.
}