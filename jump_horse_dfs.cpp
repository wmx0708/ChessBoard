////������ȱ���Ѱ�����·��
//#include<iostream>
//#include<stack>
//#include<tuple>
//#include<string>
//#include<limits.h>
//using namespace std;
//
//int ex2, ey2;
//int ans = INT_MAX;//ans���ڴ洢���·�������������������Ҫʹ�ã��ʶ�����Ϊȫ�ֱ���
//
//bool check(int x, int y)//�����纯��
//{
//    return x >= 1 && x <= 8 && y >= 1 && y <= 8;
//}
//
//void dfs(int x, int y)
//{
//    int height = 0, st, nx, ny;//���Լ�¼ջ�ߣ�ÿ��·���и�����������Լ��������Ĳ���
//    int dx[8] = { 1,1,2,2,-1,-1,-2,-2 }, dy[8] = { 2,-2,1,-1,2,-2,1,-1 };//8�ֶ�Ӧ�߷�
//    bool mp[9][9] = { 0 };//λ�÷��ʱ��,0Ϊ���Է��ʣ�1Ϊ��ֹ����
//    stack<tuple<int, int, int>> stk;//����һ��ջ��ʵ���������
//    //������ѹջ��x,yΪ������꣬0λ�����Լ�¼ջ�и�Ԫ������·�������Ĳ���
//    stk.push(make_tuple(x, y, 0));
//    mp[x][y] = 1;//�ֽ����ڵ�����Ϊ��ֹ����
//    while (stk.empty() == 0)//��ջ�ǿ�ʱ
//    {
//        tuple<int, int, int> tmp = stk.top();//����ջԪ����������int����Ԫ��
//        stk.pop();//����ջ��Ԫ��
//        cout << "(" << get<0>(tmp) << "," << get<1>(tmp) << ")" << " ";
//        cout << get<2>(tmp) << " " << endl; 
//        for (int i = 0; i < 8; i++)//����8���߷�
//        {
//            nx = get<0>(tmp) + dx[i];//����һ���������
//            ny = get<1>(tmp) + dy[i];
//            st = get<2>(tmp) + 1;//����һ��������һ
//            //�������һ���Ժ�δԽ���ҵ����λ�ÿ��Է���
//            if (check(nx, ny) && mp[nx][ny] == 0)
//            {
//                mp[nx][ny] = 1;//����λ����Ϊ��ֹ����
//                cout << "(" << nx << "," << ny << ")" << " ";
//                cout << "st " << st << " ";
//                //����λ�����յ㣬�Ƚ�·����֮ǰ��¼�����յ��·��Ѱ����Сֵ
//                if (nx == ex2 && ny == ey2) 
//                {
//                    mp[nx][ny] = 0;
//                    if (ans > st + 1)
//                        ans = st;
//                    //���ڸ�λ��ǰһ��λ����һ�����򵽴����յ㣬��������ز�����һ�������յ㣬��ֱ�ӽ�����ǰѭ��
//                    break;
//                }
//                else 
//                {
//                    if (st < ans) //����λ�ò����յ����䲽��С�����·��������Ԫ����ջ
//                        stk.push(make_tuple(nx, ny, get<2>(tmp) + 1));
//                }
//            }
//        }
//        if (height - 1 == stk.size())//��û��Ԫ����ջ�����Ϊ����㣬������һ��
//        {
//            mp[get<0>(tmp)][get<1>(tmp)] = 0;//������һ��ǰ����λ����Ϊ���Է���
//            height = stk.size();//ջ�߸�ֵ��ǰջ��
//        }
//        else//��Ԫ����ջ,����ǻ��㣬ջ�߸�ֵ��ǰջ��
//            height = stk.size();
//        cout << " ans " << ans << endl;
//    }
//    return;
//}
//
//string s, e;//sΪ����ַ�����eΪ�յ��ַ���
//int main()
//{
//    string s_1[64], s_2[64];
//    int cnt = 0, move[50];
//    while (cin >> s >> e)
//    {
//        cin.get();
//        if (s == "#" && e == "#")
//            break;
//        s_1[cnt] = s;
//        s_2[cnt] = e;
//        int sx = s[0] - 'a' + 1;
//        int sy = s[1] - '0';
//        ex2 = e[0] - 'a' + 1, ey2 = e[1] - '0';
//        dfs(sx, sy);
//        move[cnt++] = ans;
//        ans = INT_MAX;
//    }
//    for (int i = 0; i < cnt; i++)
//    {
//        cout << s_1[i] << "==>" << s_2[i] << ": " << move[i] << "moves" << endl;
//    }
//    return 0;
//}
