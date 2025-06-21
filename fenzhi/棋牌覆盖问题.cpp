#include<iostream>
using namespace std;

int box[100][100];
int num = 0;
void chessBoard(int x, int y, int a, int b, int length) 
{
	//如果棋盘简化为1×1，该方格为一特殊方格
	if (length == 1)
	{  
		return;
	}
	int h = length / 2;   //分割棋盘为原来的一半
	int t = ++num;        //L型骨牌号,从1开始
	//左上角
	if (a < x + h && b < y + h)
	{   //特殊方格在此棋盘中
		chessBoard(x, y, a, b, h);   
	}else
	{   //覆盖右下角的方格再划分
		box[x + h - 1][y + h - 1] = t;
		chessBoard(x, y, x + h - 1, y + h- 1, h);
	}
	//右上角
	if (a < x + h && b >= y + h)
	{  //特殊方格在此棋盘中
		chessBoard(x, y + h, a, b, h);
	}else
	{   //覆盖右下角的方格再划分
		box[x + h - 1][y + h] = t;
		chessBoard(x, y + h, x + h - 1, y + h, h);
	}
	//右下角
	if (a >= x + h && b >= y + h)
	{  //特殊方格在此棋盘中
		chessBoard(x + h, y + h, a, b, h);
	}else
	{   //覆盖右下角的方格再划分
		box[x + h][y + h] = t;
		chessBoard(x + h, y + h, x + h, y + h, h);
	}
	//左下角
	if (a >= x + h && b < y + h)
	{  //特殊方格在此棋盘中
		chessBoard(x + h, y, a, b, h);
	}else
	{   //覆盖右下角的方格再划分
		box[x + h][y + h - 1] = t;
		chessBoard(x + h, y, x + h, y + h - 1, h);
	}
}

int main()
{
    int x, y, k;
    scanf("%d%d%d", &k, &x, &y);
	//左上角方格：1行1列，特殊方格：4行2列，棋盘为8×8
	chessBoard(1, 1, x, y, 1<<k);
	for (int i = 1; i <= 1<<k; i++)
	{
		for (int j = 1; j <= 1<<k; j++)
		{
			cout << box[i][j];
		}
		cout << endl;
	}
	return 0;
}
