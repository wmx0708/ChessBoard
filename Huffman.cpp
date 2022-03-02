//#include <iostream>
//#include<iomanip>
//#include <queue>
//#include <vector>
//#include <map>
//#include <string>
//
//using namespace std;
//int enter[50];//�洢�����ַ�Ƶ��
//class Node {
//public:
//    //char c; //��ʾ�ַ�
//    int frequency, id; //frequency��ʾ���ַ����ֵĴ�����Ƶ�ʣ�id��ʾ���ַ��ĳ��ִ���
//    Node* left;
//    Node* right;
//
//    Node(int f,Node* l = NULL, Node* r = NULL)
//        :frequency(f), left(l), right(r) { }
//    //�ṹ����Ƕ�ȽϺ���
//    bool operator<(const Node& node) const { //����<���㷨�������ڼ������ȶ��е�ʱ�������δ�����λ��
//        if (frequency == node.frequency) return id < node.id;
//        return frequency > node.frequency;
//    }
//};
//
////���ȶ���Ĭ��Ϊ�Ӵ�С,����������ȶ����ǰ�frequencyС�����ȳ��ӣ���Ϊ���ݽṹ�嶨��frequencyС��node��
//void initNode(priority_queue<Node>& q, int nodeNum, int* f) {
//    for (int i = 0; i < nodeNum; i++) {
//        enter[i] = f[i];
//        Node node(f[i]);
//        node.id = i;
//        q.push(node);
//    }
//}
//
////չʾ���н������Ƶ��
//void showNode(priority_queue<Node> q) {
//    while (!q.empty()) {
//        Node node = q.top(); 
//        q.pop();
//        cout << node.frequency << endl;
//    }
//}
//
////�����������
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
//// ��ӡ����������
//void huffmanCode(Node* root, string& prefix, map<int, string>& result) {
//    string m_prefix = prefix; //prefix���ڴ洢���ڵ�Ĺ���������
//
//    if (root->right == NULL)
//        return;
//
//    //����������
//    prefix += "1";
//    //�����Ҷ�ӽ�������,����ݹ��ӡ������
//    if (root->right->right == NULL)
//        result[root->right->frequency] = prefix;
//    //cout << root->left->c << ": " << prefix << endl;
//    else
//        huffmanCode(root->right, prefix, result);
//
//    //��ԭԭ����·��,����
//    prefix = m_prefix;
//
//    //����������
//    prefix += "0";
//    //�����Ҷ�ӽ�㣬�����, ����ݹ��ӡ������
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
//        //����map����
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
//    int t,nodeNum[20], f[20][50];//���ݵ�����,ÿ�����ݵ����ݸ�����ÿ�����ݵ�����
//    //cout << "���ι������뼸�����ݣ�";
//    cin >> t;
//    for (int i = 0; i < t; i++) {
//        //cout << "������Ƶ�����еĳ��ȣ�";
//        cin >> nodeNum[i];
//        for (int j = 0; j < nodeNum[i]; j++) {
//            //cout << "������Ƶ�����У�";
//            cin >> f[i][j];
//        }
//    }
//    cout << endl;
//    for (int i = 0; i < t; i++)
//    {
//        cout << "Case " << i + 1 << endl;
//        priority_queue<Node> q;
//
//        //��ʼ���ַ���Ϣ
//        initNode(q, nodeNum[i],f[i]);
//        //showNode(q);
//
//        //�����������
//        huffmanTree(q, nodeNum[i]);
//
//        //�������������
//        Node root = q.top();
//        string prefix = "";
//        map<int, string> result;
//        huffmanCode(&root, prefix, result);
//        
//        //��ӡHuffman��
//        print(nodeNum[i], result);
//        cout << endl;
//    }
//    return 0;
//}