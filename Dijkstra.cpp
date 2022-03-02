//#include<iostream>
//#include<limits.h>
//#include<iomanip>
//using namespace std;
//
//const int maxint = INT_MAX;
//
//int length[49];//����������·���еıߵ�������¼��
//template<class Type >
//void Dijkstra(int n, int v, Type dist[], int* prev, Type c[][50]) {
//	bool s[50];//��¼S�����еĵ�
//	for (int i = 1; i <= n; i++) {
//		dist[i] = c[v - 1][i - 1];
//		length[i] = 1;
//		s[i] = false;//��ʼ�����еĵ�����ڼ�����
//		if (dist[i] == -1) {
//			prev[i] = 0;//dist[i]==-1����iδ�����ֱ������
//			dist[i] = maxint;//���õ��·��ֵ�ȸ�ֵΪ�����
//		}
//		else
//			prev[i] = v;//���򣬸õ������ֱ��������·��ǰһ����Ϊ��ʼ��
//	}
//	dist[v] = 0; s[v] = true;//��㵽�Լ���·��ֵΪ0��Ĭ���ʼ�ڼ�����
//	for (int i = 1; i <= n; i++) {
//		int temp = maxint;//temp���ڼ�¼����dist[]�����е���Сֵ
//		int u = v;//u���ڼ�¼dist[]�е���Сֵ��Ӧ�ĵ�
//		for (int j = 1; j <= n; j++)//��dist[]����Сֵ
//			if ((!s[j]) && (dist[j] != 0) && (dist[j] <= temp))
//			{
//				if (dist[j] < temp) {
//					u = j;
//					temp = dist[j];
//				}
//				else //���dist[]����Сֵ������������ȡ����ĸ��С��ֵ
//					if (u < j) {
//						u = j;
//						temp = dist[j];
//					}
//			}
//		s[u] = true;//�ҵ��󽫶������S����
//		for (int j = 1; j <= n; j++) {
//			if ((!s[j]) && (c[u - 1][j - 1] > 0))  {//Ѱ��������֮��ĸ���·��
//				Type newdist = dist[u] + c[u - 1][j - 1];
//				if (newdist < dist[j]) 
//				{
//					dist[j] = newdist;
//					prev[j] = u;
//					length[j] = length[u] + 1;
//				}
//				else if (newdist == dist[j])//������·����ȣ�ȡ·�����������ٵ�
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
//	//num[]�洢ÿ�����������n,���������
//	//c[][][]�洢ÿ����������Ķ�ά���飬��·������
//	//v[][]�洢ÿ��������������ֵ���յ�ֵ��v[][0]Ϊ��㣬v[][1]Ϊ�յ�
//	int dist[50], prev[50], path[49];
//	while (cin>> n)
//	{
//		if (cin.get() != '#')//��#��Ϊ���������־
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
//		//ͨ��prev�����ѯ���·�������Ķ��㲢�������path����
//		while (prev[node]) { 
//			path[cnt] = node;
//			node = prev[node];
//			cnt++;
//		}
//		path[cnt] = node;
//		//������ǰ��Ѱ��·�����ʶ��������path��cnt��¼���·���������
//		for (int j = cnt; j > 0; j--) {
//			if (j != 1) 
//				cout << path[j] << "->";
//			else
//				cout << path[j] << endl;
//		}
//	}
//}