//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <deque>
//#include <list>
//#include <sstream>
//using namespace std;
//int main()
//{
//    string s;
//    stringstream ss;
//    int val_1 = 10;
//    ss << val_1;
//    ss >> s;
//    
//    //ss.str("");
//    //ss.clear();
//    
//
//    double val_2 = 12.3;
//    // 未清空，转化失败
//    ss << val_2;
//    ss >> s;
//    
//    cout << s << endl;
//    return 0;
//}
//// 转化是指：其它类型到string，若转化过一次，
#include <string>
#include <iostream>
using namespace std;
struct Node
{
	Node(int val = 0)
		: _val(val)
		, _left(nullptr)
		, _right(nullptr)
	{}
	int _val;
	Node* _left;
	Node* _right;
};
void dfs(Node* root, string& str)
{
	// 到达叶节点
	if (root->_left == nullptr && root->_right == nullptr)
	{
		cout << str << endl;
		// str.pop_back();
		return;
	}
	// 遍历左树
	if (root->_left)
	{
		str.push_back('0');
		dfs(root->_left, str);
		str.pop_back();
	}
	if (root->_right)
	{
		str.push_back('1');
		dfs(root->_right, str);
		str.pop_back();
	}
	// if (!str.empty())
	//	str.pop_back();
}
int Tree()
{
	Node* root = new Node(18);
	Node* l1 = new Node(9);
	Node* r1 = new Node(9);
	Node* r2 = new Node(4);
	Node* r3 = new Node(5);
	Node* r4 = new Node(1);
	Node* r5 = new Node(3);
	root->_left = l1;
	root->_right = r1;
	r1->_left = r2;
	r1->_right = r3;
	r2->_left = r4;
	r2->_right = r5;
	string ans;
	dfs(root, ans);
	return 1;
}


int main()
{
	Tree();
	return 0;
}