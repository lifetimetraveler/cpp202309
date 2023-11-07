#include <iostream>
using namespace std;
const int numCell = 3; // �������� ���� ���� ����

//�Է¹��� ��ǥ�� Ÿ�缺�� �����ϴ� �Լ�.
bool isValid(int x, int y, char board[][numCell]);
//���� üũ�ڵ� �Լ�
bool checkWin(char board[][numCell], char currentUser);

int main() {
	// ������ �����ϴ� �� �ʿ��� ���� ����
	const int USERNUM = 3;
	const int numCell = 3; // �������� ���� ���� ����
	int k = 0; // ���� �������� üũ�ϱ� ���� ����
	char currentUser = 'X'; // ���� ������ ���� �����ϱ� ���� ����
	char board[numCell][numCell]{}; // �������� ��Ÿ���� 2���� �迭
	int x, y = 0; // ����ڿ��� xy��ǥ���� �Է¹ޱ� ���� ����

	// ������ �ʱ�ȭ
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// ������ ���� �ݺ�
	while (true) {
		// 1. ���� �������� ���
		// TODO 1.1: 3�ο� �������� ����
		switch (k % USERNUM) {//�ݺ�Ƚ���� �������� ���� �������� ���� ���� ������ ����
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
		//� ������ �������� ���
		cout << k % USERNUM + 1 << "�� ����(" << currentUser << ")�� �����Դϴ�. -> ";

		// 2. ��ǥ �Է� �ޱ�
		cout << "(x, y) ��ǥ�� �Է��ϼ���: ";
		int x, y;
		cin >> x >> y;

		// 3. �Է¹��� ��ǥ�� ��ȿ�� üũ
		// TODO FUNC 1: isValid �Լ� ���� �� ȣ��
		
		//��ȿ���� ������(�Լ��� false�� ��ȯ) ���� ���� ����
		if (isValid(x, y,board)==false)
		{
			continue;
		}//true��� ���� �ڵ�� ����



		// 4. �Է¹��� ��ǥ�� ���� ������ �� ����
		board[x][y] = currentUser;

		// 5. ���� ���� �� ���
		// TODO 1.2: numCell ���ڿ� ���� ������ ���
		for (int i = 0; i < numCell; i++) 
		{
			//�� y�࿡ �� ������ ���� �տ��� �����Ͽ� �� õ���� �ȴ�.
			for (int k = 0; k < numCell - 1; k++)//�����Ǻ��� �ϳ� ���� �ݺ��ϰ�
			{
				cout << "---|";

			}cout << "---\n";//������ �ѹ��� �̰����� ä���.

			for (int j = 0; j < numCell; j++)//�� y�࿡ �����Ͽ� x���� ���� �� ĭ���̸� ���ʷ� ���.
			{
				cout << " " << board[i][j] << " ";
			
				if (j == numCell - 1) {//������������ ĭ���̸� ���� �ʴ´�.
					break;
				}
				cout<< "|";//ĭ���� ����
			}
			cout << endl;
		}
		//���� �������� ����Ͽ� �� �عٴ��� ���� �Ѳ�
		for (int k = 0; k < numCell - 1; k++)//������ ���� �ѹ� ���� �����ϰ�
		{
			cout << "---|";

		}cout << "---\n";//�� �������� �����ش�.



		bool isWin = false;
		isWin = checkWin(board,currentUser);// �¸� ���θ� ����. 
		// TODO FUNC2: 6.1���� 6.2���� checkWin �Լ� ���� �� ȣ��
		



		// �¸��ڰ� �����Ǿ����� �ش� �÷��̾ ����ϰ� ������ �����Ѵ�.
		if (isWin == true) {//�¸��� ���� ���� �¸��ڿ� �޼��� ���.
			cout << k % USERNUM + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			break;
		}

		// 7. ��� ĭ �� á���� üũ�ϱ�
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {//��� �迭�� Ž���ϰ� ������ �ִٸ� checked�� �ø�
					checked++;//��, ������ ���� checked�� ����� ��.
				}
			}
		}
		if (checked == 0) {//checked�� 0�̸�, ������ ���ٸ� ����
			cout << "��� ĭ�� �� á���ϴ�.  �����մϴ�. " << endl;
			break;
		}

		k++;//Ƚ���� �ø���.
	}

	return 0;
}

//�Է¹��� ��ǥ�� Ÿ�缺�� �����ϴ� �Լ�. �ùٸ� ��ǥ�� true�� ���, �ƴϸ� false�� ���.
bool isValid(int x, int y, char board[][numCell])
{
	if (x >= numCell || y >= numCell) {// ��ǥ ������ �����
		cout << x << "," << y << ": x�� y���� �ϳ��� ĭ�� ����ϴ�. " << endl;
		return false;
	}
	if (board[x][y] != ' ') {// ��ǥ������ �Է°��� �ߺ��ɶ�. ��ǥ�� ������ �ƴѰ��
		cout << x << "," << y << ": �̹� ���� ���ֽ��ϴ�. " << endl;
		return false;
	}
	return true;
}

//�¸� �ڵ�üũ�� ���� �Լ�. �¸� ������ �����Ǹ� true�� ��ȯ. ��� ���ǵ� �� ���߸� ���� false�� ��ȯ.
bool checkWin(char board[][numCell], char currentUser)
{
	// 6.1. ����/���� �� üũ�ϱ�
	for (int i = 0; i < numCell; i++) {//�� y�� ���� ���� ��� Ȯ���Ͽ� ��� ���ٸ� true�� ��ȯ
		if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
			cout << "���ο� ��� ���� �������ϴ�!!";
			return true;
			break;
		}
		//�� x�� ���� ������ ��� Ȯ���Ͽ� ��� ���ٸ� true�� ��ȯ
		if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
			cout << "���ο� ��� ���� �������ϴ�!!";
			return true;
			break;
		}
	}
	// 6.2. �밢���� üũ�ϱ�
	// TODO 1.3: numCell�� ���� �밢�� ���� üũ �ڵ�� Ȯ��
	// HINT: for ��

	//�⺻������ ��� �迭�� Ȯ���Ͽ� ����� �Ĺ��� �������� �������� Ȯ���Ѵ�.
	//board�� ĭ ������ 1�� ���� �����ϸ�, �迭�� ���Ĺ� ���� Ȯ���Ѵ�.
	//board�� ĭ ��-1���� Ȯ���� ������ ���Ĺ��� ���� ���������� ���ٸ�(��user���) ���� �ϼ��� ���̴�.

	//�»���� ���ϴ� �밢���� Ȯ��
	int bc = 0;//��ġȽ���� üũ�ϱ� ���� ����

	for (int i = 0; i < numCell - 1; i++)//�밢������ �¸��� ���� �ʿ��� ĭ�� ���� board�� ũ��� ����.
	{//���� board�� ũ��-1��ŭ ���Ĺ��� �迭�� ������ Ȯ���Ѵ�.
		if (board[i][i] == board[i + 1][i + 1] && board[i][i] != ' ' && board[i + 1][i + 1] != ' ')
		{//board�� ����� �Ĺ��� ������ �ƴϰ�, �� ���� ���ٸ� ��ġȽ���� ����
			bc++;//�Ĺ��� �迭�� [����+1][����+1]
		}

	}

	if (bc == numCell - 1)//��ġ Ƚ���� for���� �ݺ�Ƚ���� ���ٸ� true�� ��ȯ.
	{
		cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!";
		return true;
	}

	//���ϴܺ��� ������ Ȯ��
	int bd = 0;//��ġȽ���� üũ�ϱ� ���� ����
	for (int i = 0; i < numCell - 1; i++)//�밢������ �¸��� ���� �ʿ��� ĭ�� ���� board�� ũ��� ����.
	{
		if (board[numCell - 1 - i][i] != ' ' && board[numCell - 2 - i][i + 1] != ' ')
		{//���Ĺ��� ������ �ƴϰ�
			if (board[numCell - 1 - i][i] == board[numCell - 2 - i][i + 1])
			{//���Ĺ��� ���� ���ٸ� Ƚ���� ����
				bd++;//�Ĺ��� �迭�� [����-1][����+1]
			}
		}
	}
	if (bd == numCell - 1)//��ġ Ƚ���� for���� �ݺ�Ƚ���� ���ٸ� true�� ��ȯ.
	{
		cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!";
		return true;
	}
	return false;//���� ��� ������ �����ϸ� false�� ��ȯ.
}