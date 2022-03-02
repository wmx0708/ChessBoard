//#include <iostream>
//#include<string>
//#include <vector>
//#include <set>
//using namespace std;
//
//class Solution {
//public:
//    //������������г���
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
//    // �ҳ����е�LCS������
//    // �����β�lcs_str������Ϊ���ã�������Ҫÿ�ε���lcs_str����������һ������
//    void PrintAllLCS(string& x, string& y, int m, int n, string lcs_str) {
//        while (m > 0 && n > 0) {
//            if (x[m - 1] == y[n - 1]) {
//                lcs_str = x[m - 1] + lcs_str;
//                --m;
//                --n;
//            }
//            //�൱�ڷ��š��I��
//            else {
//                if (c[m - 1][n] > c[m][n - 1])  //�����ߡ�����
//                    --m;
//                else if (c[m - 1][n] < c[m][n - 1])  //�����ߡ�����
//                    --n;
//                //��ʱ�������Ҿ�ΪLCS��Ԫ��
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
//    int array[10],array1[10];//array���Դ洢���������Ӵ����ȣ�array2���Դ洢����������еĸ���
//    string array2[10][50];//���Դ洢���������������
//    int array3[10][50][50], array4[10][50][50];//���Դ洢b,c��
//    int array5[10], array6[10];//���Դ洢m,n
//    cin >> num;
//    for (int i = 0; i < num; i++) {
//        string x, y;
//        int count = 0, count1 = 0;//����������еĸ���,b������
//        cin >> m >> n;
//        array5[i] = m;array6[i] = n;
//        //��ȡ"\n"
//        cin.get();
//        //�����ַ������пո�ֱ��cinֻ���ȡ���ո�ǰ���ʲ���getline()
//        getline(cin, x);
//        getline(cin, y);
//        //ȥ���ַ����еĿո�
//        x.erase(std::remove(x.begin(), x.end(), ' '), x.end());
//        y.erase(std::remove(y.begin(), y.end(), ' '), y.end());
//        Solution s;//��������
//        string lcs_str;//�洢�����������
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
//        //��Casei��������������д�������
//        set<string>::iterator iter = s.all_lcs.begin();
//        while (iter != s.all_lcs.end()) {
//            array2[i][count++]=*iter++;
//        }
//        array1[i] = count;//count��ʾCasei���ڵ�����������и���
//    }
//
//    //�������������г����Լ����������������
//    for (int j = 0; j < num; j++) {
//        cout << endl << endl;
//        cout << "Case" << j + 1 << endl;
//        cout << "����������еĳ��ȣ�" << array[j] << endl;
//        cout << "LCS(X,Y):" << endl;
//        for (int k = 0; k < array1[j]; k++) {
//            cout << array2[j][k] << endl;
//        }
//        cout << endl << "c��";
//        for (int p = 0; p < array5[j]; p++)  {
//            cout << endl;
//            for (int q = 0; q < array6[j]; q++)
//                cout << array4[j][p][q];
//        }
//        cout << endl;
//        cout << endl << "b��";
//        for (int p = 0; p < array5[j]; p++) {
//            cout << endl;
//            for (int q = 0; q < array6[j]; q++)
//                cout << array3[j][p][q];
//        }
//    }
//
//    return 0;
//}
