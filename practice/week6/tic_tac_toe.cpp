#include<iostream>
using namespace std;

int main()
{
	const int numCell = 3;//게임이 몇 칸이 될지를 선언
	char board[numCell][numCell]{};//칸의 역할을 할 배열 선언
	int x, y;//좌표값 입력을 위한 변수 선언

	//전체 보드판을 ' '로 초기화
	for (x = 0; x < numCell; x++)//앞의 인덱스
	{
		for (y= 0; y < numCell; y++)//뒤의 인덱스
		{
			board[x][y] = ' ';//초기화를 위한 문장
		}
	}

	
	int k = 0;//차례 확인을 위한 변수
	char currentUser = 'X';//돌 모양이 될 변수

	//게임 실행을 위한 무한 루프
	while (true)//무한 루프
	{
		//1. 차례를 출력
		switch (k % 2)//k를 2로 나눈값이
		{
		case 0://k가 짝수일 때
			cout << k % 2 + 1 << "번 유저(X)의 차례입니다 -> ";
			currentUser = 'X';//x로 돌 모양을 바꿈
				break;
		case 1://k가 홀수일 떄
			currentUser = 'O';//O로 돌 모양을 바꿈
			cout << k % 2 + 1 << "번 유저(o)의 차례입니다 -> ";
		}

		//2. 돌을 놓을 좌표 입력
		cout << "(x,y) 좌표를 입력하세요: ";
		cin >> x >> y;

		//3. 받은 좌표 값이 유효성을 벗어났을 때
		if (x >= numCell || y >= numCell)//x나 y가 칸을 벗어나서 입력받으면
		{
			cout << x << "," << y << ": ";
			cout << "x 와 y 둘 중 하나가 칸을 벗어납니다." << endl;
			continue;//루프 맨 앞으로
		}
		if (board[x][y] != ' ')//x나 y가 빈칸(' ')이 아닐 때, 이미 돌이 놓였을 때
		{
			cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
			continue;//루프 맨 앞으로
		}

		//4. 돌을 놓기 위해서 배열을 초기화
		board[x][y] = currentUser;

		//5. 게임의 틀이 되는 부분 출력 및 돌도 함께 출력
		for (int i = 0; i < numCell; i++)//칸 수 만큼 반복
		{
			cout << "---|---|---" << endl;//직선 칸 출력
			for (int j = 0; j < numCell; j++)//각 줄에 왔을 때 칸 수만큼 반복
			{
				cout << board[i][j];//돌 모양을 출력
				if (j == numCell - 1)//칸의 끝에 오면 탈출하기 바로 위 for문을 탈출
				{
					break;
				}
				cout << "  |";// 중간 |를 출력
			}
			cout << endl;//다음 칸으로 넘어감
		}
		cout << "---|---|---" << endl;//맨 아랫 칸 출력

		//6. 빙고 시 승자 출력 후 종료
		bool isWin = false;
		//6. 1. 직선인 경우 체크
		for (int i = 0; i < numCell; i++)//각 가로줄이나 세로줄 이 모두 같은지를 확인
		{
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser)
			{
				cout << "가로에 모두 돌이 놓였습니다!: ";
				isWin = true;
			}
			if(board[0][i]==currentUser && board[1][i] == currentUser&& board[2][i] == currentUser)
			{
				cout << "세로에 모두 돌이 놓였습니다!: ";
				isWin = true;
			}
		}
		//6.2. 대각선 체크
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser)
		{
			cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
				isWin = true;
		}
		if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser)
		{
			cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
				isWin = true;
		}
		//종료를 위한 코드 
		if (isWin == true)//종료 조건인 isWin이 트루가되면 종료
		{
			cout << k % 2 + 1<<"번 유저(" << currentUser << ")의 승리입니다!" << endl;
			cout << "종료합니다" << endl;
			break;
		}



		//7. 모든 칸 다 찼는지 확인
		int checked = 0;
		for (int i = 0; i < numCell; i++)
		{
			for (int j = 0; j < numCell; j++)
			{
				if (board[i][y] == ' ')//공란일 경우 checked를 올림
				{
					checked++;
				}

			}
			
		}
		if (checked == 0)//모든 칸에 공란이 없는경우
		{
			cout << "모든 칸이 다 찼습니다. 종료합니다" << endl;
			break;
		}
		


		k++;//차례를 확인을 위해서 1을 더해줌
	}
	return 0;
}