#include<iostream>
using namespace std;

int main()
{
	const int numCell = 3;//������ �� ĭ�� ������ ����
	char board[numCell][numCell]{};//ĭ�� ������ �� �迭 ����
	int x, y;//��ǥ�� �Է��� ���� ���� ����

	//��ü �������� ' '�� �ʱ�ȭ
	for (x = 0; x < numCell; x++)//���� �ε���
	{
		for (y= 0; y < numCell; y++)//���� �ε���
		{
			board[x][y] = ' ';//�ʱ�ȭ�� ���� ����
		}
	}

	
	int k = 0;//���� Ȯ���� ���� ����
	char currentUser = 'X';//�� ����� �� ����

	//���� ������ ���� ���� ����
	while (true)//���� ����
	{
		//1. ���ʸ� ���
		switch (k % 2)//k�� 2�� ��������
		{
		case 0://k�� ¦���� ��
			cout << k % 2 + 1 << "�� ����(X)�� �����Դϴ� -> ";
			currentUser = 'X';//x�� �� ����� �ٲ�
				break;
		case 1://k�� Ȧ���� ��
			currentUser = 'O';//O�� �� ����� �ٲ�
			cout << k % 2 + 1 << "�� ����(o)�� �����Դϴ� -> ";
		}

		//2. ���� ���� ��ǥ �Է�
		cout << "(x,y) ��ǥ�� �Է��ϼ���: ";
		cin >> x >> y;

		//3. ���� ��ǥ ���� ��ȿ���� ����� ��
		if (x >= numCell || y >= numCell)//x�� y�� ĭ�� ����� �Է¹�����
		{
			cout << x << "," << y << ": ";
			cout << "x �� y �� �� �ϳ��� ĭ�� ����ϴ�." << endl;
			continue;//���� �� ������
		}
		if (board[x][y] != ' ')//x�� y�� ��ĭ(' ')�� �ƴ� ��, �̹� ���� ������ ��
		{
			cout << x << ", " << y << ": �̹� ���� ���ֽ��ϴ�." << endl;
			continue;//���� �� ������
		}

		//4. ���� ���� ���ؼ� �迭�� �ʱ�ȭ
		board[x][y] = currentUser;

		//5. ������ Ʋ�� �Ǵ� �κ� ��� �� ���� �Բ� ���
		for (int i = 0; i < numCell; i++)//ĭ �� ��ŭ �ݺ�
		{
			cout << "---|---|---" << endl;//���� ĭ ���
			for (int j = 0; j < numCell; j++)//�� �ٿ� ���� �� ĭ ����ŭ �ݺ�
			{
				cout << board[i][j];//�� ����� ���
				if (j == numCell - 1)//ĭ�� ���� ���� Ż���ϱ� �ٷ� �� for���� Ż��
				{
					break;
				}
				cout << "  |";// �߰� |�� ���
			}
			cout << endl;//���� ĭ���� �Ѿ
		}
		cout << "---|---|---" << endl;//�� �Ʒ� ĭ ���

		//6. ���� �� ���� ��� �� ����
		bool isWin = false;
		//6. 1. ������ ��� üũ
		for (int i = 0; i < numCell; i++)//�� �������̳� ������ �� ��� �������� Ȯ��
		{
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser)
			{
				cout << "���ο� ��� ���� �������ϴ�!: ";
				isWin = true;
			}
			if(board[0][i]==currentUser && board[1][i] == currentUser&& board[2][i] == currentUser)
			{
				cout << "���ο� ��� ���� �������ϴ�!: ";
				isWin = true;
			}
		}
		//6.2. �밢�� üũ
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser)
		{
			cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!: ";
				isWin = true;
		}
		if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser)
		{
			cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!: ";
				isWin = true;
		}
		//���Ḧ ���� �ڵ� 
		if (isWin == true)//���� ������ isWin�� Ʈ�簡�Ǹ� ����
		{
			cout << k % 2 + 1<<"�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			cout << "�����մϴ�" << endl;
			break;
		}



		//7. ��� ĭ �� á���� Ȯ��
		int checked = 0;
		for (int i = 0; i < numCell; i++)
		{
			for (int j = 0; j < numCell; j++)
			{
				if (board[i][y] == ' ')//������ ��� checked�� �ø�
				{
					checked++;
				}

			}
			
		}
		if (checked == 0)//��� ĭ�� ������ ���°��
		{
			cout << "��� ĭ�� �� á���ϴ�. �����մϴ�" << endl;
			break;
		}
		


		k++;//���ʸ� Ȯ���� ���ؼ� 1�� ������
	}
	return 0;
}