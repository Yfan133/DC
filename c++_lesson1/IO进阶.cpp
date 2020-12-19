/*
C语言的标准输入：
	gets(char* );在输入之前必须先进行设置好容量
	scanf();	 返回值：成功接收的"个数"
	get();
	getchar();	 可以用来接收空格或者回车
C语言的标准输出：
	printf();				返回值：成功输出的"个数"
	printf("%s ", "hello"); 返回值：6
	puts();
	putchar();
C++的IO流：
	cin： 底层是istream
	cout：底层是ostream，重载了所有的内置类型
	cerr：标准错误
	clog：日志信息
	geline(cin, )：查一下cin和geline的返回值
C语言文件IO流
	fopen("文件名"， "打开格式")
	fread(buf, 元素个数, 元素类型大小, 文件指针fp)	以二进制方式读取
	fscanf()
	fgets()
	fgetc()

	fwrite(buf, 元素个数, 元素类型大小, 文件指针fp)
	fwrite(buf, 1, sizeof(buf), fp);一般都把元素个数设为1，大小为sizeof(buf)
	ftell(FILE* fp); 返回文件指针在文件中的位置
	fseek(FILE* fp, 偏移量, 偏移方式);
		fseek(fp, 0, SEEK_END)
	feof(fp)  检测文件指针是否在文件的末尾

面试题：
1.什么是文本文件？什么是二进制文件？
	举个例子：如果有数据 a = 5；存入文本文件：5 二进制文件：101
2.如何检测一个文件指针是否在文件末尾？
	文本文件：只要返回值不为EOF，EOF的本质是-1
	二进制文件：用feof(fp)检测，因为-1用二进制在内存中是全F，一字节：FF会被当成EOF

C++文件IO流：头文件 <fstream>
	ifstream ifile  == FILE
	ofstream ofile
	fstream  ffile

C++将整型转换成string类型：头文件<sstream>
	stringstream ss;
	ss << a;
	ss >> buf;
	注意每次转换之前都要
	ss.str("")	清空stringstream内部的字符串
	ss.clear()	清空stringstream内部的状态，否则下次不会进行转化。注：只是清空了状态，但是内部管理的字符串没有清空
*/