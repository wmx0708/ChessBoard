//#include <iostream>
//#include<string>
//#include <vector>
//#include <set>
//using namespace std;
//
//class Solution {
//public:
//    //求最长公共子序列长度
//    int lengthOflongestCommonSequence(string& x, string& y, int m, int n) {
//        if (m == 0 || n == 0)
//            return 0;
//        c = vector<vector<int> >(m + 1, vector<int>(n + 1, 0));
//        b = vector<vector<int> >(m + 1, vector<int>(n + 1, 0));
//        for (int i = 1; i < m + 1; ++i) {
//            for (int j = 1; j < n + 1; ++j) {
//                if (x[i - 1] == y[j - 1]) {
//                    c[i][j] = c[i - 1][j - 1] + 1;
//                    b[i][j] = 0;
//                }
//                else if (c[i - 1][j] >= c[i][j - 1]) {
//                    c[i][j] = c[i - 1][j];
//                    b[i][j] = 1;
//                }
//
//                else {
//                    c[i][j] = c[i][j - 1];
//                    b[i][j] = 2;
//                }
//            }
//        }
//        return c[m][n];
//    }
//    // 找出所有的LCS的序列
//    // 这里形参lcs_str不可以为引用，这里需要每次调用lcs_str都重新生成一个对象
//    void PrintAllLCS(string& x, string& y, int m, int n, string lcs_str) {
//        while (m > 0 && n > 0) {
//            if (x[m - 1] == y[n - 1]) {
//                lcs_str = x[m - 1] + lcs_str;
//                --m;
//                --n;
//            }
//            //相当于符号“↖”
//            else {
//                if (c[m - 1][n] > c[m][n - 1])  //向左走“←”
//                    --m;
//                else if (c[m - 1][n] < c[m][n - 1])  //向上走“↑”
//                    --n;
//                //此时向上向右均为LCS的元素
//                else {
//                    PrintAllLCS(x, y, m - 1, n, lcs_str);
//                    PrintAllLCS(x, y, m, n - 1, lcs_str);
//                    return;
//                }
//            }
//        }
//        all_lcs.insert(lcs_str);
//    }
//    vector<vector<int>> c;
//    vector<vector<int>> b;
//    set<string> all_lcs;
//};
//
//int main()
//{
//    int num, m, n;
//    int array[10],array1[10];//array用以存储输出最长公共子串长度，array2用以存储最长公共子序列的个数
//    string array2[10][50];//用以存储所有最长公共子序列
//    int array3[10][50][50], array4[10][50][50];//用以存储b,c表
//    int array5[10], array6[10];//用以存储m,n
//    cin >> num;
//    for (int i = 0; i < num; i++) {
//        string x, y;
//        int count = 0, count1 = 0;//最长公共子序列的个数,b表行数
//        cin >> m >> n;
//        array5[i] = m;array6[i] = n;
//        //读取"\n"
//        cin.get();
//        //由于字符串中有空格，直接cin只会读取到空格前，故采用getline()
//        getline(cin, x);
//        getline(cin, y);
//        //去除字符串中的空格
//        x.erase(std::remove(x.begin(), x.end(), ' '), x.end());
//        y.erase(std::remove(y.begin(), y.end(), ' '), y.end());
//        Solution s;//创建对象
//        string lcs_str;//存储最长公共子序列
//        int res = s.lengthOflongestCommonSequence(x, y, m, n);
//        array[i] = res;
//        for (int j = 0; j < m; j++) {
//            for (int k = 0; k < n; k++)
//            {
//                array3[i][j][k] = s.b[j][k];
//                array4[i][j][k] = s.c[j][k];
//            }
//        }
//            
//        //cout << res << endl;
//        s.PrintAllLCS(x, y, m, n, lcs_str);
//        //将Casei所有最长公共子序列存入数组
//        set<string>::iterator iter = s.all_lcs.begin();
//        while (iter != s.all_lcs.end()) {
//            array2[i][count++]=*iter++;
//        }
//        array1[i] = count;//count表示Casei存在的最长公共子序列个数
//    }
//
//    //输出最长公共子序列长度以及所有最长公共子序列
//    for (int j = 0; j < num; j++) {
//        cout << endl << endl;
//        cout << "Case" << j + 1 << endl;
//        cout << "最长公共子序列的长度：" << array[j] << endl;
//        cout << "LCS(X,Y):" << endl;
//        for (int k = 0; k < array1[j]; k++) {
//            cout << array2[j][k] << endl;
//        }
//        cout << endl << "c表：";
//        for (int p = 0; p < array5[j]; p++)  {
//            cout << endl;
//            for (int q = 0; q < array6[j]; q++)
//                cout << array4[j][p][q];
//        }
//        cout << endl;
//        cout << endl << "b表：";
//        for (int p = 0; p < array5[j]; p++) {
//            cout << endl;
//            for (int q = 0; q < array6[j]; q++)
//                cout << array3[j][p][q];
//        }
//    }
//
//    return 0;
//}
