

// 优先级队列操作
//int main()
//{
//	vector<int> arr = { 1,2,3,6,8,10 };
//	Test1();
//	Test2();
//	//sort(arr.begin(), arr.end(), [](int a, int b) {return a > b; });
//	return 0;
//}

// 优先级队列模拟实现
//int main()
//{
//	TestMyPriorityQueue1();
//	TestMyPriorityQueue2();
//	return 0;
//}

// 智能指针模拟实现
//int main()
//{
//	
//	// Test1();
//	// Test2();
//	// Test3();
//	// Test4();
//	// Test5();
//	// TestThread();
//	// Test6();
//	// Test7();
//	
//	return 0;
//}

// 闭散列模拟实现
//#include "hashTable.h"
//int main()
//{
//	TestHt();
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;

/*
1.类型强转
	强转内置类型会生成临时变量，强转地址不会生成临时变量。
	因为强转了地址，只是指定这块地址按照什么方式进行解析
2.this类型：type* const，this可以为空，但是如果成员函数中调用了成员变量或者成员函数则代码崩溃
3.必须在构造函数初始化列表进行初始化的：
	const成员变量
	引用
	自定义类型的成员变量(其内部有全缺省或者无参构造)
4.const 修饰的对象，只能调用const修饰的成员函数
  const 修饰的成员函数，里面只能调用const修饰的成员函数
5.C语言的类型和其所表示范围
	char			-128~127
	short			-2^15~2~15-1
	int				-2^31~2^31-1
	long			
	long long
	float
	double
6.static修饰的
	成员变量：

	成员函数

	C语言中的：
	函数：
	全局变量：
	局部变量：
7.浮点数的存储
	二进制的标准科学计数法：M 一定是 1.xxx，因此不需要存1，只需要存后面的 XXX
	中间数 127，存+127，取-127，则指数位E是
		注意：指数E为0，代表浮点数为0(规定！！)
	浮点数的零值不是唯一的，通常表示一个区间,（f < MIN && f > -MIN）

*/