////������ȱ�����������ȱ���Ѱ�����·��
//#include<iostream>
//#include<queue>
//#include<tuple>
//#include<string>
//#include<stack>
//#include<limits.h>
//#include<time.h>
//#include<stdio.h>
//using namespace std;
//
//int dx[8] = { 1,1,2,2,-1,-1,-2,-2 }, dy[8] = { 2,-2,1,-1,2,-2,1,-1 };//8�ֶ�Ӧ�߷�
//int ex, ey;//�յ�����
//int ans1 = 0,ans2 = INT_MAX;//ans���ڴ洢���·�������������������Ҫʹ�ã��ʶ�����Ϊȫ�ֱ���
//
//bool check(int x, int y)//�����纯��
//{
//    return x >= 1 && x <= 8 && y >= 1 && y <= 8;
//}
//void bfs(int x, int y)
//{
//    int st, height = 0, nx, ny;//���Լ�¼���������и߶ȡ��������
//    queue<tuple<int, int, int>> que;
//    que.push(make_tuple(x, y, 0));//x,yΪ������꣬0λ�����Լ�¼���и�Ԫ�ص����Ĳ���
//    while (que.empty() == 0)
//    {
//        tuple<int, int, int> tmp = que.front();
//        que.pop();
//        /*cout << "(" << get<0>(tmp) << "," << get<1>(tmp) << ")" << " ";
//        cout << get<2>(tmp) << " " << endl;*/
//        for (int i = 0; i < 8; i++)//����8���߷�
//        {
//            nx = get<0>(tmp) + dx[i];//������һ����������������x,y
//            ny = get<1>(tmp) + dy[i];
//            int st = get<2>(tmp) + 1;
//            if (check(nx, ny))
//            {
//                /*cout << "(" << nx << "," << ny << ")" << " ";
//                cout << "st " << st << " ";*/
//                que.push(make_tuple(nx, ny, get<2>(tmp) + 1));//����λ�������
//                if (nx == ex && ny == ey)//�����ߵ��յ㣬��˵�������·��
//                {
//                    ans1 = st;
//                    //cout << " ans " << ans1 << endl;
//                    return;
//                }
//            }
//        }
//        //cout << " ans " << ans1 << endl;
//    }
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
//        /*cout << "(" << get<0>(tmp) << "," << get<1>(tmp) << ")" << " ";
//        cout << get<2>(tmp) << " " << endl;*/
//        for (int i = 0; i < 8; i++)//����8���߷�
//        {
//            nx = get<0>(tmp) + dx[i];//����һ���������
//            ny = get<1>(tmp) + dy[i];
//            st = get<2>(tmp) + 1;//����һ��������һ
//            //�������һ���Ժ�δԽ���ҵ����λ�ÿ��Է���
//            if (check(nx, ny) && mp[nx][ny] == 0)
//            {
//                mp[nx][ny] = 1;//����λ����Ϊ��ֹ����
//                /*cout << "(" << nx << "," << ny << ")" << " ";
//                cout << "st " << st << " ";*/
//                //����λ�����յ㣬�Ƚ�·����֮ǰ��¼�����յ��·��Ѱ����Сֵ
//                if (nx == ex && ny == ey)
//                {
//                    mp[nx][ny] = 0;
//                    if (ans2 > st + 1)
//                        ans2 = st;
//                    //���ڸ�λ��ǰһ��λ����һ�����򵽴����յ㣬��������ز�����һ�������յ㣬��ֱ�ӽ�����ǰѭ��
//                    break;
//                }
//                else
//                {
//                    if (st < ans2) //����λ�ò����յ����䲽��С�����·��������Ԫ����ջ
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
//        //cout << " ans " << ans2 << endl;
//    }
//    return;
//}
//
//string s1, s2;
//int main()
//{
//    double duration1[50], duration2[50];
//    clock_t start1, start2, end1, end2;
//    string s_1[64], s_2[64];
//    int cnt = 0,move1[50],move2[50];
//    while (cin >> s1 >> s2)
//    {
//        cin.get();
//        if (s1 == "#" && s2 == "#")
//            break;
//        s_1[cnt] = s1;
//        s_2[cnt] = s2;
//        int sx = s1[0] - 'a' + 1;
//        int sy = s1[1] - '0';
//        ex = s2[0] - 'a' + 1, ey = s2[1] - '0';
//        start1 = clock();
//        bfs(sx, sy);
//        end1 = clock();
//        duration1[cnt] = (double)(end1 - start1) / CLK_TCK;
//        move1[cnt] = ans1;
//        start2 = clock();
//        dfs(sx, sy);
//        end2 = clock();
//        duration2[cnt] = (double)(end2 - start2) / CLK_TCK;
//        move2[cnt++] = ans2;
//        ans2 = INT_MAX;
//    }
//    cout << "bfs:" << endl;
//    for (int i = 0; i < cnt; i++)
//    {
//        cout << s_1[i] << "==>" << s_2[i] << ": " << move1[i] << "moves";
//        printf(" time:%f\n", duration1[i]);
//    }
//    cout << "dfs:" << endl;
//    for (int i = 0; i < cnt; i++)
//    {
//        cout << s_1[i] << "==>" << s_2[i] << ": " << move2[i] << "moves";
//        printf(" time:%f\n", duration2[i]);
//    }
//    return 0;
//}
