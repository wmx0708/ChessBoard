//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include<stdio.h>
//#include<math.h>
//#include <iomanip>
//#include<string>
//
//using namespace std;
////static int tile = 1;
//int tile = 1;//l型骨牌的编号
////static int Board[1024][1024];
//int Board[1024][1024];//棋盘最大为1024*1024
//
//void Chessboard(int tr, int tc, int dr, int dc, int size) {
//	/*
//	tr:当前棋盘左上角的行号
//	tc:当前棋盘左上角的列号
//	dr:当前特殊方格所在行号
//	dc:当前特殊方格所在列号
//	size:棋盘的宽度，长度
//	*/
//	if (size == 1) {//当方格为1*1时说明递归完成
//		return;
//	}
//	int t = tile++;//骨牌每次递增1
//	int s = size / 2;//每次递归，缩减棋盘规模
//	//检查特殊方格是否在左上角的子棋盘中
//	if (dr < tr + s && dc < tc + s) {
//		Chessboard(tr, tc, dr, dc, s);
//	}
//	else//特殊方格不在此子棋盘，将该棋盘右下角的方块视为特殊方块
//	{
//		Board[tr + s - 1][tc + s - 1] = t;
//		Chessboard(tr, tc, tr + s - 1, tc + s - 1, s);
//	}
//	//检查特殊方格是否在右上角的子棋盘中
//	if (dr < tr + s && dc >= tc + s) {
//		Chessboard(tr, tc + s, dr, dc, s);
//	}
//	else//特殊方格不在此子棋盘，将该棋盘左下角的方块视为特殊方块
//	{
//		Board[tr + s - 1][tc + s] = t;
//		Chessboard(tr, tc + s, tr + s - 1, tc + s, s);
//	}
//	//检查特殊方格是否在左下角的子棋盘中
//	if (dr >= tr + s && dc < tc + s) {
//		Chessboard(tr + s, tc, dr, dc, s);
//	}
//	else//特殊方格不在此子棋盘，将该棋盘右上角的方块视为特殊方块
//	{
//		Board[tr + s][tc + s - 1] = t;
//		Chessboard(tr + s, tc, tr + s, tc + s - 1, s);
//	}
//	//检查特殊方格是否在右下角的子棋盘中
//	if (dr >= tr + s && dc >= tc + s) {
//		Chessboard(tr + s, tc + s, dr, dc, s);
//	}
//	else//特殊方格不在此子棋盘，将该棋盘左上角的方块视为特殊方块
//	{
//		Board[tr + s][tc + s] = t;
//		Chessboard(tr + s, tc + s, tr + s, tc + s, s);
//	}
//
//}
//int main() {
//	//x，y为特殊方格的二维数组下标，k为棋盘大小2^k中的幂的大小,row为输入数据的行数
//	int x, y, k, row = 0;
//	int array[100][3];//用于存放若干行输入数据的数组
//	while (cin >> k >> x >> y)//用循环实现若干行数据的输入
//	{
//		if (cin.get() != '#')//"#"为数据输入终止的标志
//		{
//			//数组中依次存放每行输入数据k、x、y的值
//			array[row][0] = k;
//			array[row][1] = x;
//			array[row][2] = y;
//			row++;
//		}
//		else
//			break;
//	}
//
//	//逐行取出输入数据进行棋盘覆盖处理
//	for (int m = 0; m < row; m++)
//	{
//		tile = 1;//每行数据tile变量都要重新赋值为1
//		//array[m][1]、array[m][2]即每行数据中对应的x、y值
//		Board[array[m][1]][array[m][2]] = 0;//棋盘中的特殊方格先赋值为0
//		int size = (int)pow(2, array[m][0]);//size=2^k
//		Chessboard(0, 0, array[m][1], array[m][2], size);//调用棋盘覆盖函数
//		//采用循环将二维数组中的数据输出
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = 0; j < size; j++)
//				if (Board[i][j] == 0)//识别到特殊方格则输出“#”
//					//setw（）控制数字的域宽保证二维数组输出列的整齐度
//					cout << setw(4) << "#" << " ";
//				else
//					cout << setw(4) << Board[i][j] << " ";
//			cout << endl;
//		}
//		cout << endl;
//	}
//	return 0;
//}
