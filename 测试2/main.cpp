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
#include <iostream>
using namespace std;

struct S1	// 对齐数 = 默认对齐数 和 该成员大小较小值
{			// 12
	char c1;
	int i;
	char c2;
};
//练习2
struct S2	// 8
{
	char c1;
	char c2;
	int i;
};

//练习3
struct S3	// 16
{
	double d;
	char c;
	int i;
};


int main()
{
	printf("%d\n", sizeof(struct S1));
	printf("%d\n", sizeof(struct S2));
	printf("%d\n", sizeof(struct S3));
	return 0;
}