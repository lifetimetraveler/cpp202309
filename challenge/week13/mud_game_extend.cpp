#include <iostream>
#include <string>
#include "user.h"
using namespace std;
//맵의 크기를 상수로 선언
const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y, int user2_x,int user2_y);
bool checkGoal(int map[][mapX], int user_x, int user_y,int user2_x,int user2_y);
void opti(int& user_x, int mapX, int& user_y, int mapY);
bool CheckUser(User user);//유저의 채력 확인을 위한 함수.
//추가 기능

//객체의 참조자를 사용하여서 객체의 변수를 이 함수에서 직접 바꿈.
void checkState(int map[][mapX], User& user);//유저가 무언가 만났을 때의 반응을 위한 함수. 유저의 위치 확인 후 hp 변환
	int current_hp;//각 차례에 맞는 사용자의 체력을 저장하기 위함
// 메인  함수
int main() {

	Magician m(20);//위자드를 체력 20으로 생성
	Warrior w(20);//워리어를 체력 20으로 생성
	
	int turn = 0;//차례를 확인하기 위함

	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},//배열에 여러 오브젝트들을 할당
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };

	


	
	
	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프
		//차례를 확인//그 차례인 유저의 Hp와 차례라는 문구를 출력.
		if (turn % 2 == 0)
		{
			cout << "Magician의 차례입니다." << endl;
			current_hp = m.GetHP();
		}
		else if(turn % 2 == 1)
		{
			cout << "Warrior의 차례입니다." << endl;
			current_hp = w.GetHP();
		}

		//Hp가 0이면 종료를 위함
		if (CheckUser(current_hp) == false)//CheckUser()가 false 즉, hp가 0이하인경우
		{
			cout << "Hp가 0이 되었습니다. 혼자 남은 유저는 습격을 당했습니다." << endl << "게임을 종료합니다.";
			break;
		}
		// 사용자의 입력을 저장할 변수
		string user_input = "";
		cout << "현재 HP: " << current_hp;//현재 차례의 사용자 hp 표시
		cout << "명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;

		if (user_input == "상") {//입력 받은 값이 상일 경우
			if (turn % 2 == 0)//매지션의 차례
			{
				m.user_y -= 1;// 위로 한 칸 올라가기
				bool inMap = checkXY(m.user_x, mapX, m.user_y, mapY);//이동한 값이 타당한지를 확인하는 함수. 잘못되면 flase를 출력. inMap은 그 값을 받기 위한 변수
				if (inMap == false) {//위의 함수가 false를 출력한 경우
					opti(m.user_x, mapX, m.user_y, mapY);
					continue;
				}
				else {//입력 받은 이동 값이 타당한 경우
					cout << "위로 한 칸 올라갑니다." << endl;//메세지와 맵을 출력하는 함수를 실행
					displayMap(map, m.user_x, m.user_y, w.user_x, w.user_y);//맵을 표시
					m.DecreaseHP(1);//이동이 유효하여 이동 했으니 객체 함수를 호출하여 HP를 감소시킴  
					checkState(map,  m);//적, 포션 등을 만났을 때 반응및 메세지를 위한 함수
					if (m.wound)//적을 만난경우
					{
						m.doAttack();
						m.wound = 0;
					}
				}
			}
			else if(turn % 2 == 1)//워리어의 차례
			{
				// 위로 한 칸 올라가기
				w.user_y -= 1;
				bool inMap = checkXY(w.user_x, mapX, w.user_y, mapY);//이동한 값이 타당한지를 확인하는 함수. 잘못되면 flase를 출력. inMap은 그 값을 받기 위한 변수
				if (inMap == false) {//위의 함수가 false를 출력한 경우
					opti(w.user_x, mapX, w.user_y, mapY);
					continue;
				}
				else {//입력 받은 이동 값이 타당한 경우
					cout << "위로 한 칸 올라갑니다." << endl;//메세지와 맵을 출력하는 함수를 실행
					displayMap(map, m.user_x, m.user_y, w.user_x, w.user_y);//맵 표시
					w.DecreaseHP(1);//이동이 유효하여 이동 했으니 객체 함수를 호출하여 HP를 감소시킴  
					checkState(map,  w);//적, 포션 등을 만났을 때 반응및 메세지를 위한 함수
					if (w.wound)//적을 만난경우
					{
						w.doAttack();
						w.wound = 0;
					}
				}
			}
			
		}
		else if (user_input == "하") {//상과 원리가 동일. x나 y의 값만 그에 맞게 설정
			// TODO: 아래로 한 칸 내려가기
			
			if (turn % 2 == 0)//매지션의 차례
			{
				m.user_y += 1;// 위로 한 칸 올라가기
				bool inMap = checkXY(m.user_x, mapX, m.user_y, mapY);//이동한 값이 타당한지를 확인하는 함수. 잘못되면 flase를 출력. inMap은 그 값을 받기 위한 변수
				if (inMap == false) {//위의 함수가 false를 출력한 경우
					opti(m.user_x, mapX, m.user_y, mapY);
					continue;
				}
				else {//입력 받은 이동 값이 타당한 경우
					cout << "위로 한 칸 올라갑니다." << endl;//메세지와 맵을 출력하는 함수를 실행
					displayMap(map, m.user_x, m.user_y, w.user_x, w.user_y);//맵 표시
					m.DecreaseHP(1);//이동이 유효하여 이동 했으니 객체 함수를 호출하여 HP를 감소시킴  
					checkState(map,  m);//적, 포션 등을 만났을 때 반응및 메세지를 위한 함수
					if (m.wound)//적을 만난 경우
					{
						m.doAttack();
						m.wound = 0;
					}
				}
			}
			else if (turn % 2 == 1)//워리어의 차례
			{
				// 위로 한 칸 올라가기
				w.user_y += 1;
				bool inMap = checkXY(w.user_x, mapX, w.user_y, mapY);//이동한 값이 타당한지를 확인하는 함수. 잘못되면 flase를 출력. inMap은 그 값을 받기 위한 변수
				if (inMap == false) {//위의 함수가 false를 출력한 경우
					opti(w.user_x, mapX, w.user_y, mapY);
					continue;
				}
				else {//입력 받은 이동 값이 타당한 경우
					cout << "위로 한 칸 올라갑니다." << endl;//메세지와 맵을 출력하는 함수를 실행
					displayMap(map, m.user_x, m.user_y, w.user_x, w.user_y);//맵표시
					w.DecreaseHP(1);//이동이 유효하여 이동 했으니 객체 함수를 호출하여 HP를 감소시킴  
					checkState(map,  w);//적, 포션 등을 만났을 때 반응및 메세지를 위한 함수
					if (w.wound)//적을 만난 경우
					{
						w.doAttack();
						w.wound = 0;
					}
				}
			}
		}
		else if (user_input == "좌") {//상과 원리가 동일. x나 y의 값만 그에 맞게 설정
			if (turn % 2 == 0)//매지션의 차례
			{
				m.user_x -= 1;// 위로 한 칸 올라가기
				bool inMap = checkXY(m.user_x, mapX, m.user_y, mapY);//이동한 값이 타당한지를 확인하는 함수. 잘못되면 flase를 출력. inMap은 그 값을 받기 위한 변수
				if (inMap == false) {//위의 함수가 false를 출력한 경우
					opti(m.user_x, mapX, m.user_y, mapY);
					continue;
				}
				else {//입력 받은 이동 값이 타당한 경우
					cout << "위로 한 칸 올라갑니다." << endl;//메세지와 맵을 출력하는 함수를 실행
					displayMap(map, m.user_x, m.user_y, w.user_x, w.user_y);//맵표시
					m.DecreaseHP(1);//이동이 유효하여 이동 했으니 객체 함수를 호출하여 HP를 감소시킴  
					checkState(map, m);//적, 포션 등을 만났을 때 반응및 메세지를 위한 함수
					if (m.wound)//적을 만난 경우
					{
						m.doAttack();
						m.wound = 0;
					}
				}
			}
			else if (turn % 2 == 1)//워리어의 차례
			{
				// 위로 한 칸 올라가기
				w.user_x -= 1;
				bool inMap = checkXY(w.user_x, mapX, w.user_y, mapY);//이동한 값이 타당한지를 확인하는 함수. 잘못되면 flase를 출력. inMap은 그 값을 받기 위한 변수
				if (inMap == false) {//위의 함수가 false를 출력한 경우
					opti(w.user_x, mapX, w.user_y, mapY);
					continue;
				}
				else {//입력 받은 이동 값이 타당한 경우
					cout << "위로 한 칸 올라갑니다." << endl;//메세지와 맵을 출력하는 함수를 실행
					displayMap(map, m.user_x, m.user_y, w.user_x, w.user_y);//맵 표시
					w.DecreaseHP(1);//이동이 유효하여 이동 했으니 객체 함수를 호출하여 HP를 감소시킴  
					checkState(map, w);//적, 포션 등을 만났을 때 반응및 메세지를 위한 함수
					if (w.wound)//적을 만난 경우
					{
						w.doAttack();
						w.wound = 0;
					}
				}
			}
		}
		else if (user_input == "우") {//상과 원리가 동일. x나 y의 값만 그에 맞게 설정
			if (turn % 2 == 0)//매지션의 차례
			{
				m.user_x += 1;// 위로 한 칸 올라가기
				bool inMap = checkXY(m.user_x, mapX, m.user_y, mapY);//이동한 값이 타당한지를 확인하는 함수. 잘못되면 flase를 출력. inMap은 그 값을 받기 위한 변수
				if (inMap == false) {//위의 함수가 false를 출력한 경우
					opti(m.user_x, mapX, m.user_y, mapY);
					continue;
				}
				else {//입력 받은 이동 값이 타당한 경우
					cout << "위로 한 칸 올라갑니다." << endl;//메세지와 맵을 출력하는 함수를 실행
					displayMap(map, m.user_x, m.user_y, w.user_x, w.user_y);//맵표시
					m.DecreaseHP(1);//이동이 유효하여 이동 했으니 객체 함수를 호출하여 HP를 감소시킴  
					checkState(map, m);//적, 포션 등을 만났을 때 반응및 메세지를 위한 함수
					if (m.wound)//적을 만난 경우
					{
						m.doAttack();
						m.wound = 0;
					}
				}
			}
			else if(turn % 2 == 1)//워리어의 차례
			{
				// 위로 한 칸 올라가기
				w.user_x += 1;
				bool inMap = checkXY(w.user_x, mapX, w.user_y, mapY);//이동한 값이 타당한지를 확인하는 함수. 잘못되면 flase를 출력. inMap은 그 값을 받기 위한 변수
				if (inMap == false) {//위의 함수가 false를 출력한 경우
					opti(w.user_x, mapX, w.user_y, mapY);
					continue;
				}
				else {//입력 받은 이동 값이 타당한 경우
					cout << "위로 한 칸 올라갑니다." << endl;//메세지와 맵을 출력하는 함수를 실행
					displayMap(map, m.user_x, m.user_y, w.user_x, w.user_y);//맵을 표시
					w.DecreaseHP(1);//이동이 유효하여 이동 했으니 객체 함수를 호출하여 HP를 감소시킴  
					checkState(map, w);//적, 포션 등을 만났을 때 반응및 메세지를 위한 함수
					if (w.wound)//적을 만난 경우
					{
						w.doAttack();
						w.wound = 0;
					}
				}
			}
		}
		else if (user_input == "지도") {//지도를 입력 받은 경우
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, m.user_x, m.user_y,w.user_x,w.user_y);
			continue;//지도를 봐도 차례가 넘어가지 않도록
		}
		else if (user_input == "종료") {//종료를 입력한 경우
			cout << "종료합니다.";
			break;//break로 무한 루프를 탈출
		}
		else {//위의 경우가 아닌 다른 것을 입력한경우
			cout << "잘못된 입력입니다." << endl;
			continue;//다시 위로 돌아감
		}

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, m.user_x, m.user_y,w.user_x,w.user_y);//유저가 목적지를 도달하면 true를 반환하는 함수와 그 값을 받기 위한 변수
		if (finish == true) {//변수에 트루가 할당된경우 즉, 도착지의 좌표와 유저 인풋좌표가 같아질 때.
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;//성공 메세지 출력과 무한 루프 종료
			cout << "게임을 종료합니다." << endl;
			break;

			
		}
		turn++;

	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y,int user2_x,int user2_y) {//배열과 입력 좌표를 매개변수로 받음
	for (int i = 0; i < mapY; i++) {//맵의 세로만큼 반복
		for (int j = 0; j < mapX; j++) {//맵의 각 세로에서 가로만큼 반복
			//각 배열을 탐색하되 그 배열에 유저가 있을 때에는 유저를 출력, 그 배열에 유저가 존재하지 않으면 원래 위치한 오브젝트를 출력
			//각 메세지를 출력할 때 가로를 나누는 칸도 출력
			
			if (user_x == user2_x && user_y == user2_y && user_x == j && user_y == i)
			{
				cout << "  mw  |";
			}
            else if (i == user_y && j == user_x) {//그 반복 시기 때 좌표와 입력좌표가 같으면
				cout << "   m  |"; // 양 옆 1칸 공백 //유저를 출력
			}
			else if (i == user2_y && j == user2_x) {//그 반복 시기 때 좌표와 입력좌표가 같으면
				cout << "   w  |"; // 양 옆 1칸 공백 //유저를 출력
			}
			else {//유저 존재하지 않는 칸의 반복을 시행하고 있을 때
				int posState = map[i][j];//이때는 지도의 배열에 해당하는 값(아이템, 적 등)을 변수에 받아옴
				switch (posState) {
				case 0://빈 공간일 경우
					cout << "      |"; // 6칸 공백
					break;
				case 1://아이템을 경우
					cout << "아이템|";
					break;
				case 2://적일 경우
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3://포션일 경우
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4://목적지일 경우
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;//세로의 반복문을 실행할 때 1회 시행할 때마다 출력하여서 세로간의 경계가 됨
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;//반환값을 위한 변수를 선언
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {//입력 좌표가 0이상이여야 하고 맵의 크기보다 작을 경우
		checkFlag = true;//트루를 할당하여 유효한 좌표임을 출력
	}
	return checkFlag;// 받은 값 출력
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y,int user2_x,int user2_y) {// 입력 좌표값과 배열을 매개변수로
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {//입력 좌표의 값이 들어간 배열에 목적지가 있으면
		cout << "magicina이 승리했습니다." << endl;
		return true;//트루를 출력
	}
	else if (map[user2_y][user2_x]==4)
	{
		cout << "worrior가 승리했습니다." << endl;
		return true;//트루를 출력
	}
	return false;//if 가 실행되지 않은 목적지가 아니면 false를 출력
}

void checkState(int map[][mapX],User& user)
{
	int posState = map[user.user_y][user.user_x];//각 배열 인덱스에 있는 값을 받을 변수를 선언 및 그 배열의 값으로 초기화
	switch (posState)//즉, 그 배열에 어떤 것이 들어있는지 확인하고 그에대한 반응을 함.
	{
	case 0://공란일 경우, 아무것도 하지 않음
		break;
	case 1://아이템일 경우
		cout << "아이템을 만났습니다.\n";//아이템을 만났다는 함수 출력
		break;
	case 2://적을 만난 경우
		cout << "적을 만났습니다. Hp가 2 줄어듭니다.\n";//메세지 출력
		user.wound++;//적을 만났음을 표시하기 위해 사용
	    user.DecreaseHP(2);//데미지를 줌//객체 함수로 체력 2을 감소
		break;
	case 3://포션을 만난경우
		cout << "포션을 획득했습니다. Hp가 2 늘어납니다.\n";//메세지를 출력하고 회복을함
		user.IncreaseHP(2);//객체함수에 접근하여 2를 가산
	case 4://목적지인 경우 아무것도 하지 않음
		break;
	}
}

//오류 메세지 출력 및 이동 취소
void opti(int& user_x, int mapX, int& user_y, int mapY) 
{//맵 바깥으로 나가는 네 가지의 상황에 맞는 좌표 값의 수정
	cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;//오류 메세지를 출력하기 위함
	if (user_x >= mapX)//맵보다 좌표가 커지면
	{
		user_x -= 1;
	}
	else if (user_x < 0)//맵의 바깥으로 나가면
	{
		user_x += 1;
	}
	else if (user_y >= mapY)//맵보다 좌표가 커지면
	{
		user_y -= 1;
	}
	else if (user_y < 0)//좌표가 바깥으로 나가면
	{
		user_y += 1;
	}
	
}

bool CheckUser(User user) {
	if (user.GetHP() <= 0)//객체의 hp를 반환하는 함수 사용하여 체력을 얻음.
		return false;
	else
		return true;
}