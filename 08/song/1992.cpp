#include <stdio.h>

#define MAXSIZE 64

bool matrix[MAXSIZE][MAXSIZE] = { false, };

bool canCompress(int x, int y, int size)
{
	bool flag = matrix[y][x]; //(x,y)를 flag로 선언하고
	for (int row = 0;row < size;row++)
	{
		for (int col = 0;col < size;col++)
		{
			if (matrix[y + row][x + col] != flag) //flag와 다른 값이 있으면
				return false; //압축 불가
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
		compress(x, y, dividedSize); //좌측 상단
		compress(x + dividedSize, y, dividedSize); //우측 상단
		compress(x, y + dividedSize, dividedSize); //좌측 하단
		compress(x + dividedSize, y + dividedSize, dividedSize); //우측 하단
		printf(")");
	}
}

int main()
{
	int n; //영상의 크기
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