////深度优先遍历寻找最短路径
//#include<iostream>
//#include<stack>
//#include<tuple>
//#include<string>
//#include<limits.h>
//using namespace std;
//
//int ex2, ey2;
//int ans = INT_MAX;//ans用于存储最短路径，由于主函数输出需要使用，故而设置为全局变量
//
//bool check(int x, int y)//检测出界函数
//{
//    return x >= 1 && x <= 8 && y >= 1 && y <= 8;
//}
//
//void dfs(int x, int y)
//{
//    int height = 0, st, nx, ny;//用以记录栈高，每条路径中各个点的坐标以及距离起点的步数
//    int dx[8] = { 1,1,2,2,-1,-1,-2,-2 }, dy[8] = { 2,-2,1,-1,2,-2,1,-1 };//8种对应走法
//    bool mp[9][9] = { 0 };//位置访问标记,0为可以访问，1为禁止访问
//    stack<tuple<int, int, int>> stk;//定义一个栈以实现深度优先
//    //将顶点压栈，x,y为马的坐标，0位置用以记录栈中各元素所经路径到起点的步数
//    stk.push(make_tuple(x, y, 0));
//    mp[x][y] = 1;//现将根节点设置为禁止访问
//    while (stk.empty() == 0)//当栈非空时
//    {
//        tuple<int, int, int> tmp = stk.top();//定义栈元素中有三个int类型元素
//        stk.pop();//弹出栈顶元素
//        cout << "(" << get<0>(tmp) << "," << get<1>(tmp) << ")" << " ";
//        cout << get<2>(tmp) << " " << endl; 
//        for (int i = 0; i < 8; i++)//共有8种走法
//        {
//            nx = get<0>(tmp) + dx[i];//马跳一步后的坐标
//            ny = get<1>(tmp) + dy[i];
//            st = get<2>(tmp) + 1;//马跳一步步数加一
//            //如果马跳一步以后未越界且到达的位置可以访问
//            if (check(nx, ny) && mp[nx][ny] == 0)
//            {
//                mp[nx][ny] = 1;//将该位置设为禁止访问
//                cout << "(" << nx << "," << ny << ")" << " ";
//                cout << "st " << st << " ";
//                //若该位置是终点，比较路径与之前记录到达终点的路径寻找最小值
//                if (nx == ex2 && ny == ey2) 
//                {
//                    mp[nx][ny] = 0;
//                    if (ans > st + 1)
//                        ans = st;
//                    //由于该位置前一个位置走一个方向到达了终点，其他方向必不可能一步到达终点，故直接结束当前循环
//                    break;
//                }
//                else 
//                {
//                    if (st < ans) //若该位置不是终点且其步数小于最短路径，将该元素入栈
//                        stk.push(make_tuple(nx, ny, get<2>(tmp) + 1));
//                }
//            }
//        }
//        if (height - 1 == stk.size())//若没有元素入栈，结点为死结点，回溯上一层
//        {
//            mp[get<0>(tmp)][get<1>(tmp)] = 0;//返回上一层前将该位置设为可以访问
//            height = stk.size();//栈高赋值当前栈高
//        }
//        else//有元素入栈,结点是活结点，栈高赋值当前栈高
//            height = stk.size();
//        cout << " ans " << ans << endl;
//    }
//    return;
//}
//
//string s, e;//s为起点字符串，e为终点字符串
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
