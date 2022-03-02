//#include <iostream>
//#include<iomanip>
//#include <queue>
//#include <vector>
//#include <map>
//#include <string>
//
//using namespace std;
//int enter[50];//存储输入字符频率
//class Node {
//public:
//    //char c; //表示字符
//    int frequency, id; //frequency表示该字符出现的次数或频率，id表示该字符的出现次序
//    Node* left;
//    Node* right;
//
//    Node(int f,Node* l = NULL, Node* r = NULL)
//        :frequency(f), left(l), right(r) { }
//    //结构体内嵌比较函数
//    bool operator<(const Node& node) const { //重载<运算法以至于在加入优先队列的时候决定如何处理结点位置
//        if (frequency == node.frequency) return id < node.id;
//        return frequency > node.frequency;
//    }
//};
//
////优先队列默认为从大到小,所以这个优先队列是按frequency小的优先出队，因为根据结构体定义frequency小的node大
//void initNode(priority_queue<Node>& q, int nodeNum, int* f) {
//    for (int i = 0; i < nodeNum; i++) {
//        enter[i] = f[i];
//        Node node(f[i]);
//        node.id = i;
//        q.push(node);
//    }
//}
//
////展示队列结点代表的频率
//void showNode(priority_queue<Node> q) {
//    while (!q.empty()) {
//        Node node = q.top(); 
//        q.pop();
//        cout << node.frequency << endl;
//    }
//}
//
////构造哈夫曼树
//void huffmanTree(priority_queue<Node>& q,int nodeNum) {
//    int cnt = nodeNum + 1;
//    while (q.size() != 1) {
//        Node* right = new Node(q.top()); q.pop();
//        Node* left = new Node(q.top()); q.pop();
//        Node node(left->frequency + right->frequency, left, right);
//        node.id = cnt++;
//        q.push(node);
//    }
//}
//
//
//// 打印哈夫曼编码
//void huffmanCode(Node* root, string& prefix, map<int, string>& result) {
//    string m_prefix = prefix; //prefix用于存储各节点的哈夫曼编码
//
//    if (root->right == NULL)
//        return;
//
//    //处理右子树
//    prefix += "1";
//    //如果是叶子结点则输出,否则递归打印右子树
//    if (root->right->right == NULL)
//        result[root->right->frequency] = prefix;
//    //cout << root->left->c << ": " << prefix << endl;
//    else
//        huffmanCode(root->right, prefix, result);
//
//    //还原原来的路径,回溯
//    prefix = m_prefix;
//
//    //处理左子树
//    prefix += "0";
//    //如果是叶子结点，则输出, 否则递归打印左子树
//    if (root->left->left == NULL)
//        result[root->left->frequency] = prefix;
//    //cout << root->right->c << ": " << prefix << endl;
//    else
//        huffmanCode(root->left, prefix, result);
//
//}
//
//void print(int nodeNum, map<int, string> result)
//{
//    for (int i = 0; i < nodeNum; i++) {
//        //迭代map容器
//        map<int, string>::const_iterator it = result.begin();
//        while (it != result.end()) {
//            if (it->first == enter[i]) {
//                cout << setw(4) << it->first << ": " << it->second << endl;
//                break;
//            }
//            ++it;
//        }
//    }
//}
//
//
//int main() {
//    int t,nodeNum[20], f[20][50];//数据的组数,每组数据的数据个数，每组数据的数据
//    //cout << "本次供需输入几组数据：";
//    cin >> t;
//    for (int i = 0; i < t; i++) {
//        //cout << "请输入频率序列的长度：";
//        cin >> nodeNum[i];
//        for (int j = 0; j < nodeNum[i]; j++) {
//            //cout << "请输入频率序列：";
//            cin >> f[i][j];
//        }
//    }
//    cout << endl;
//    for (int i = 0; i < t; i++)
//    {
//        cout << "Case " << i + 1 << endl;
//        priority_queue<Node> q;
//
//        //初始化字符信息
//        initNode(q, nodeNum[i],f[i]);
//        //showNode(q);
//
//        //构造哈夫曼树
//        huffmanTree(q, nodeNum[i]);
//
//        //构造哈夫曼编码
//        Node root = q.top();
//        string prefix = "";
//        map<int, string> result;
//        huffmanCode(&root, prefix, result);
//        
//        //打印Huffman树
//        print(nodeNum[i], result);
//        cout << endl;
//    }
//    return 0;
//}