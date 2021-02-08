#include <stdio.h>

#define MAXSIZE 64

bool matrix[MAXSIZE][MAXSIZE] = { false, };

bool canCompress(int x, int y, int size)
{
	bool flag = matrix[y][x]; //(x,y)�� flag�� �����ϰ�
	for (int row = 0;row < size;row++)
	{
		for (int col = 0;col < size;col++)
		{
			if (matrix[y + row][x + col] != flag) //flag�� �ٸ� ���� ������
				return false; //���� �Ұ�
		}
	}
	return true;
}

void compress(int x, int y, int size)
{
	if (canCompress(x, y, size))
		printf("%d", matrix[y][x]);
	else
	{
		printf("(");
		int dividedSize = size / 2;
		compress(x, y, dividedSize); //���� ���
		compress(x + dividedSize, y, dividedSize); //���� ���
		compress(x, y + dividedSize, dividedSize); //���� �ϴ�
		compress(x + dividedSize, y + dividedSize, dividedSize); //���� �ϴ�
		printf(")");
	}
}

int main()
{
	int n; //������ ũ��
	scanf("%d", &n);
	for (int row = 0;row < n;row++)
	{
		for (int col = 0;col < n;col++)
		{
			int num;
			scanf("%1d", &num);
			matrix[row][col] = (bool)num;
		}
	}

	compress(0, 0, n);

	return 0;
}