//#include<iostream>
//#include<cstring> 
//#include <iomanip>
//using namespace std;
//const int length = 100;//矩阵链最长长度为100
//int s[length][length], m[length][length];
//int n;
////int p[length + 1];
//
//void Matrixchain(int* p, int n) 
////*p存储矩阵的行列数，m[][]储存矩阵连乘最优次数，s[][]储存矩阵链划分位置
//{
//	memset(m, 0, sizeof(m));
//	memset(s, 0, sizeof(s));//初始化数组
//	for (int r = 2; r <= n; r++)//r表示矩阵链长度，从长度为2开始
//	{
//		for(int i = 1; i <= n - r + 1; i++)//i表示前半段链的起始点
//		{
//			int j = i + r - 1;
//			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];//对m[][]开始赋值
//			s[i][j] = i;//s[][]存储各子问题的决策点
//			for (int k = i + 1; k < j; k++)//寻找最优值
//			{
//				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
//				if (t < m[i][j])
//				{
//					m[i][j] = t;
//					s[i][j] = k;
//				}
//			}
//		}
//	}
//
//}
//
//int cnt = 0;//定义全局变量cnt(方便后续每次函数调用前赋0），当cnt==1时不输出括号，以去掉最外层括号
//void print(int i, int j)
//{
//	cnt++;
//	if (cnt == 1)
//	{
//		if (i == j)
//		{
//			cout << "A" << i;
//			return;
//		}
//
//		print(i, s[i][j]);
//		print(s[i][j] + 1, j);//递归1到s[1][j]
//	}
//	else
//	{
//		if (i == j)
//		{
//			cout << "A" << i;
//			return;
//		}
//		else
//			cout << "(";
//		print(i, s[i][j]);
//		print(s[i][j] + 1, j);//递归1到s[1][j]
//		cout << ")";
//	}
//}
//
//int main()
//{
//	int row = 0, array[100], array1[100][length + 1];//array[]存储输入数据n，array1[]存储输入数据p[]
//	int* p = NULL;
//	//输入
//	while (cin >> n) {
//		if (cin.get() != '#')//"#"为数据输入终止的标志
//		{
//			for (int j = 0; j < n+1; j++)
//				cin >> array1[row][j];
//			array[row++] = n;
//		}
//		else
//			break;
//	}
//	//输出
//	for (int i = 0; i < row; i++)
//	{
//		cout << "Case " << i + 1 << endl << endl;
//		p = array1[i];
//		Matrixchain(p, array[i]);
//		cout << m[1][array[i]];
//		cout << " ";
//		print(1, array[i]);
//		cnt = 0;
//		cout << endl << endl;;
//		cout << "m表：";
//		for (int j = 1; j <= array[i]; j++)
//		{
//			cout << endl;
//			for (int k = 1; k <= array[i]; k++)
//				cout << setw(8) << m[j][k];
//		}
//		cout << endl << endl;
//		cout << "s表：";
//		for (int j = 1; j <= array[i]; j++)
//		{
//			cout << endl;
//			for (int k = 1; k <= array[i]; k++)
//				cout << setw(8) << s[j][k];
//		}
//		cout << endl << endl;
//	}
//}
//
////int RecurMatrixChain(int i, int j)
////{
////	if (i == j)
////		return 0;
////	int u = RecurMatrixChain(i, i) + RecurMatrixChain(i + 1, j) + p[i - 1]p[i]p[j];
////	s[i][j] = i;
////	for (int k = i + 1; k < j; k++)
////	{
////		int t = RecurMatrixChain(i, k) + RecurMatrixChain(k + 1, j) + p[i - 1]p[k]p[j];
////		if (t < u)
////		{
////			u = t;
////			s[i][j] = k;
////		}
////	}
////	return u;
////}
//
////int LockupChain(int* p, int i, int j)
////{
////	if (m[i][j] > 0)//防止重复计算
////		return m[i][j];
////	if (i == j)
////		return 0;
////	int u = LockupChain(p, i, i) + LockupChain(p, i + 1, j) + p[i - 1] * p[i] * p[j];//创建矩阵链
////	s[i][j] = i;
////	for (int k = i + 1; k < j; k++)
////	{
////		int t = LockupChain(p, i, k) + LockupChain(p, k + 1, j) + p[i - 1] * p[k] * p[j];
////		if (t < u) {
////			u = t;
////			s[i][j] = k;
////		}
////	}
////	m[i][j] = u;
////	return u;
////}
////
////int MemoizedMatrixChain(int* p, int n)
////{
////	for (int i = 1; i <= n; i++) {
////		for (int j = i; j <= n; j++)
////			m[i][j] = 0;
////		return LockupChain(p, 1, n);
////	}
////}
//
