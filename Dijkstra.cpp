//#include<iostream>
//#include<limits.h>
//#include<iomanip>
//using namespace std;
//
//const int maxint = INT_MAX;
//
//int length[49];//两顶点间最短路径中的边的数量记录表
//template<class Type >
//void Dijkstra(int n, int v, Type dist[], int* prev, Type c[][50]) {
//	bool s[50];//记录S集合中的点
//	for (int i = 1; i <= n; i++) {
//		dist[i] = c[v - 1][i - 1];
//		length[i] = 1;
//		s[i] = false;//初始化所有的点均不在集合内
//		if (dist[i] == -1) {
//			prev[i] = 0;//dist[i]==-1即点i未与起点直接相连
//			dist[i] = maxint;//将该点的路径值先赋值为无穷大
//		}
//		else
//			prev[i] = v;//否则，该点与起点直接相连，路径前一个点为起始点
//	}
//	dist[v] = 0; s[v] = true;//起点到自己的路径值为0，默认最开始在集合内
//	for (int i = 1; i <= n; i++) {
//		int temp = maxint;//temp用于记录遍历dist[]后其中的最小值
//		int u = v;//u用于记录dist[]中的最小值对应的点
//		for (int j = 1; j <= n; j++)//找dist[]的最小值
//			if ((!s[j]) && (dist[j] != 0) && (dist[j] <= temp))
//			{
//				if (dist[j] < temp) {
//					u = j;
//					temp = dist[j];
//				}
//				else //如果dist[]中最小值有两个，优先取其字母序小的值
//					if (u < j) {
//						u = j;
//						temp = dist[j];
//					}
//			}
//		s[u] = true;//找到后将定点加入S集合
//		for (int j = 1; j <= n; j++) {
//			if ((!s[j]) && (c[u - 1][j - 1] > 0))  {//寻找两个点之间的更短路径
//				Type newdist = dist[u] + c[u - 1][j - 1];
//				if (newdist < dist[j]) 
//				{
//					dist[j] = newdist;
//					prev[j] = u;
//					length[j] = length[u] + 1;
//				}
//				else if (newdist == dist[j])//如果最短路径相等，取路径经过顶点少的
//				{
//					if (length[u] + 1 < length[j]) {
//						dist[j] = newdist;
//						prev[j] = u;
//						length[j] = length[u] + 1;
//					}
//				}
//			}
//
//		}
//	}
//}
//
//int main()
//{
//	int n, num[20], c[20][50][50], v[20][2], i = 0, cnt, node;
//	//num[]存储每组数据输入的n,即顶点个数
//	//c[][][]存储每组数据输入的二维数组，即路径矩阵
//	//v[][]存储每组数据输入的起点值与终点值，v[][0]为起点，v[][1]为终点
//	int dist[50], prev[50], path[49];
//	while (cin>> n)
//	{
//		if (cin.get() != '#')//‘#’为输入结束标志
//		{
//			num[i] = n;
//			for (int j = 0; j < num[i]; j++)
//				for (int k = 0; k < num[i]; k++)
//					cin >> c[i][j][k];
//			cin >> v[i][0] >> v[i][1];
//			i++;
//		}
//		else
//			break;
//	}
//	for (int m = 0; m < i; m++)
//	{
//		cnt = 1;
//		Dijkstra(num[m], v[m][0], dist, prev, c[m]);
//		node = v[m][1];
//		cout << "Case " << m + 1 << endl;
//		cout << "The least distance from " << v[m][0] << "->";
//		cout << v[m][1] << " is " << dist[v[m][1]] << endl;
//		cout << "the path is ";
//		//通过prev数组查询最短路径经过的定点并将其存入path数组
//		while (prev[node]) { 
//			path[cnt] = node;
//			node = prev[node];
//			cnt++;
//		}
//		path[cnt] = node;
//		//由于是前向寻找路径，故而逆序输出path，cnt记录最短路径定点个数
//		for (int j = cnt; j > 0; j--) {
//			if (j != 1) 
//				cout << path[j] << "->";
//			else
//				cout << path[j] << endl;
//		}
//	}
//}