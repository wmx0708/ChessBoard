//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include<stdio.h>
//#include<math.h>
//#include <iomanip>
//#include<string>
//
//using namespace std;
////static int tile = 1;
//int tile = 1;//l�͹��Ƶı��
////static int Board[1024][1024];
//int Board[1024][1024];//�������Ϊ1024*1024
//
//void Chessboard(int tr, int tc, int dr, int dc, int size) {
//	/*
//	tr:��ǰ�������Ͻǵ��к�
//	tc:��ǰ�������Ͻǵ��к�
//	dr:��ǰ���ⷽ�������к�
//	dc:��ǰ���ⷽ�������к�
//	size:���̵Ŀ�ȣ�����
//	*/
//	if (size == 1) {//������Ϊ1*1ʱ˵���ݹ����
//		return;
//	}
//	int t = tile++;//����ÿ�ε���1
//	int s = size / 2;//ÿ�εݹ飬�������̹�ģ
//	//������ⷽ���Ƿ������Ͻǵ���������
//	if (dr < tr + s && dc < tc + s) {
//		Chessboard(tr, tc, dr, dc, s);
//	}
//	else//���ⷽ���ڴ������̣������������½ǵķ�����Ϊ���ⷽ��
//	{
//		Board[tr + s - 1][tc + s - 1] = t;
//		Chessboard(tr, tc, tr + s - 1, tc + s - 1, s);
//	}
//	//������ⷽ���Ƿ������Ͻǵ���������
//	if (dr < tr + s && dc >= tc + s) {
//		Chessboard(tr, tc + s, dr, dc, s);
//	}
//	else//���ⷽ���ڴ������̣������������½ǵķ�����Ϊ���ⷽ��
//	{
//		Board[tr + s - 1][tc + s] = t;
//		Chessboard(tr, tc + s, tr + s - 1, tc + s, s);
//	}
//	//������ⷽ���Ƿ������½ǵ���������
//	if (dr >= tr + s && dc < tc + s) {
//		Chessboard(tr + s, tc, dr, dc, s);
//	}
//	else//���ⷽ���ڴ������̣������������Ͻǵķ�����Ϊ���ⷽ��
//	{
//		Board[tr + s][tc + s - 1] = t;
//		Chessboard(tr + s, tc, tr + s, tc + s - 1, s);
//	}
//	//������ⷽ���Ƿ������½ǵ���������
//	if (dr >= tr + s && dc >= tc + s) {
//		Chessboard(tr + s, tc + s, dr, dc, s);
//	}
//	else//���ⷽ���ڴ������̣������������Ͻǵķ�����Ϊ���ⷽ��
//	{
//		Board[tr + s][tc + s] = t;
//		Chessboard(tr + s, tc + s, tr + s, tc + s, s);
//	}
//
//}
//int main() {
//	//x��yΪ���ⷽ��Ķ�ά�����±꣬kΪ���̴�С2^k�е��ݵĴ�С,rowΪ�������ݵ�����
//	int x, y, k, row = 0;
//	int array[100][3];//���ڴ���������������ݵ�����
//	while (cin >> k >> x >> y)//��ѭ��ʵ�����������ݵ�����
//	{
//		if (cin.get() != '#')//"#"Ϊ����������ֹ�ı�־
//		{
//			//���������δ��ÿ����������k��x��y��ֵ
//			array[row][0] = k;
//			array[row][1] = x;
//			array[row][2] = y;
//			row++;
//		}
//		else
//			break;
//	}
//
//	//����ȡ���������ݽ������̸��Ǵ���
//	for (int m = 0; m < row; m++)
//	{
//		tile = 1;//ÿ������tile������Ҫ���¸�ֵΪ1
//		//array[m][1]��array[m][2]��ÿ�������ж�Ӧ��x��yֵ
//		Board[array[m][1]][array[m][2]] = 0;//�����е����ⷽ���ȸ�ֵΪ0
//		int size = (int)pow(2, array[m][0]);//size=2^k
//		Chessboard(0, 0, array[m][1], array[m][2], size);//�������̸��Ǻ���
//		//����ѭ������ά�����е��������
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = 0; j < size; j++)
//				if (Board[i][j] == 0)//ʶ�����ⷽ���������#��
//					//setw�����������ֵ����֤��ά��������е������
//					cout << setw(4) << "#" << " ";
//				else
//					cout << setw(4) << Board[i][j] << " ";
//			cout << endl;
//		}
//		cout << endl;
//	}
//	return 0;
//}
