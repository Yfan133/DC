/*
服务器模块
	1.试题模块：管理所有oj试题
		方式：
			1.写入文件当中，服务端从文件当中去读取
			2.保存在数据库当中
		具体实现(文件)：
			1.文件名：代表题号
			2.header.cpp：头文件
			3.desc.txt：题目的描述信息
			4.tai.cpp：测试用例，调用逻辑Solution
		文件：oj_config_cfg
			题号  题目名称  题目难度 题目路径

	2.http模块：获取请求 + 回复响应
		获取请求
			1.获取整个试题列表，http请求，方法：Get
			2.获取单个试题，http请求，方法：Get
			3.向服务器器提交代码，方法：Post，向服务器提交写出的代码

	3.其他模块：
		工具模块
			1.提供时间戳
			2.提供日志
			3.提供字符串方法

λ表达式：[](){}：[]：λ表达式传递的参数 ()：参数列表 {}：处理机制
*/

/*

code目录下的模块
	oj_data：文件信息
		1.oj_config_cfg：题目总览
		2.每个题目的详细信息
			1.desc.txt：题目描述信息
			2.header.cpp：头文件和Solution
			3.tail.cpp：调用用户的代码
	oj_model.hpp：从文件中读取试题的信息，并且返回给上层调用者
		1.Questions结构体：文件的各种信息
		2.Model类：
			Load：加载试题信息
				1.打开oj_文件，并获取所有文件的总览
				2.通过路径，获取每道题的详细信息，并保存在一个unordered_map中
			GetAllQuestions：返回全部试题
				1.通过遍历无序map把每个试题保存在vector中
				2.对vector进行排序，并返回给上层 vector<Questions> 集合
			GetOneQues：获取单个试题
				1.
	oj_server.cpp：处理浏览器的请求并且向浏览器传输数据
		1.注册Get_all_questions方法
			1.获取
			2.
		2.注册Get_one_question方法
			迫切要解决的问题：怎么区分不同的试题？
				正则表达式：R"(/question/(\d))"，但是'\d'只能识别个位数，因此'\d+'表示多位数字
				match库
			1.请求体里面：包含不同的题目id
				req[0]：请求url
				req[1]：不同的题号
			2.调用GetOneQuestion获取单个试题内容

			3.渲染单个试题的模板html，可以在菜鸟教程中练习
				testarea:文本输入框
				form：表单
				input：
		3.注册Post方法
			1.浏览器的请求
				方法：post
				url：/compile/[试题号]
				code：url编码后的代码
				tail.cpp：main函数调用 + 测试用例
			2.正则表达式通配url中的题号
			3.调用GetOneQuestion获取单个试题
			4.对提交的代码进行url切割和解码
				url是key=value&key1=value1形式
				因此对url进行处理的时候要先按照&切割，切分成不同的key=value形式
				再按照=切割，切分成 key<->value 保存到map<string,string>中
				通过key就可以在map中找到value
			5.构造json对象：把code和tail.cpp进行拼接

			修改makefile链接库
			3.编译运行模块
				1.浏览器提交的代码是没有main函数调用的
					code+tail.cpp --》 src文件
				2.编译模块进行编译
					1.创建子进程，使用子进程程序替换
					2.程序替换成g++来编译程序源码
				3.运行
					1.创建子进程，使用子进程程序替换
					2.子进程替换成为编译出来的可执行程序
				4.运行结果：返回给客户端
					错误类型：
						1.参数错误
							浏览器提交的参数为空或者参数错误							
						2.内部错误
							写文件失败
							进程程序替换失败
							内存访问失败
						3.编译错误
						4.运行错误
				5.返回运行结果
					
	tools.hpp：打开文件返回文件内容，切分字符串
		1.split
		2.
		3.获取时间戳
			返回值一定是int64_t因为时间特别大
	compile.hpp：
		1.用枚举类型去代替一个个输入
		2.
		3.使用时间戳防止生成文件时文件名相同
		4.生成到固定文件中去，./tmp_file/
		5.Compile函数，创建子进程。
			子进程：进程程序替换
			父进程：等待子进程退出
		6.运行的情况：
			1.子进程非正常退出
				1.访问空指针，内存访问越界，double free等
				2.父进程收到子进程异常的退出信号，用status收集退出信号的低7位
			2.子进程正常退出
				测试用例全部通过
				测试用例没有全部通过
			3.用sigalarm退出信号控制运行时间
			4.

	template：html的模板
	oj_view.hpp：用代码填充html的模板
		/////1.把template加到环境变量中：
		1.创建一个TemplateDictionary类对象，构造要填充name
		2.遍历vector<>填充好字典，看下setvalue函数
		3.填充html页面，先Get页面，再Expand填充字典数据
	功能扩展
		测试用例：key=value&key1=value1形式
	问题：vector没有设置容量，传到切割函数里面，为什么保存？
	json数据结构：
		json对象：a = {key:value,key1:value1}
		json数组:[1,2,3,4]
	使用：#includ <json.h>
		Json::value r;
		r["key"] = "value"
		r["key1"] = "value1"
		r ={{key:value,key1:value1}
		源码：value.h



试题信息获取：oj_model.hpp
	1.题目的描述：结构体questions
	2.从磁盘中获取题目：类OjModel
		用无序map保存：key=题号，value=结构体questions
		1.构造：调用Load函数加载试题信息
		2.析构：
		4.函数Load：加载题目信息
			1.参数题目的路径
			2.打开题目所在路径的文件
			3.获取每一行的信息，并保存在questions结构体中
				利用boost库中的split函数去切分文件中获取的一行数据
				boost::split(); 第一个：切分后放在哪
								第二个：切分的数据
								第三个：按照什么格式切分
								第四个：是否将多个分割字符看作一个，也就是多个空格也当成一个然后切割
			4.把多个question组织进unorder_map中
		5.函数GetAllQuestions：获取
			
		6.函数Get

注意：
	getline是以\n来区分的，因此我们在后面加\n
	用static修饰的函数，不用实例化对象直接，类::函数进行调用

谷歌的模板分离技术：ctemplate
	1.预定义html页面的模板，使用一个模板参数预定义到html页面当中
	2.后端代码将这些预定义模板参数的值计算完毕之后，只需要按照html模板进行更新
	
	explicit TemplateDictionary(const Template& name, UnsafeArena* arena=NULL);
		explicit：声明构造函数为显示声明
		name:可以任意指定，
		arena:

	static Template

	先填充，再融合

	标记写法：
	{{变量}}：预定义变量：{{id}}
	{{#question}}：片段标记
	{{/queation}}：片段标记结尾
*/
/*
面试时怎么介绍项目？？

解决高并发问题：
	1.cpp-httplib库中使用了select + 多线程
	2.浏览器的请求方法到来，httplib新创建了线程去处理。因此会出现并行，写文件时时间戳一样的情况，因此我们用
	3.atomic_uint id(0);这是C++中线程安全的，用atomic解决高并发时创建文件名的问题

错误类型：
	1.Req["code"]为空，则参数错误
	2.WriteTmpFile()返回的文件名是空，则是内部错误
	3.编译错误返还给浏览器的方法：修改标准错误的文件描述符，重定向到文件描述符中。
	  从文件中读取编译错误信息，然后通过Resp返回给浏览器
	
替换失败也算是内部错误吧？
在设置生成路径时，记住后面也要加/也就是 ./路径/
在g++中添加： -D CompileOnline，因此 header.cpp头文件不会引入
#ifndef CompileOnline
#include "header.cpp"
#endif
是怎么生成编译错误文件的？
是直接生成错误文件的，为什么可以通过判断是否有文件，来判断是否错误？
unlink函数删除文件
新增功能：
	时间限制：alarm
	内存限制：
	int setrlimit(int resource，const struct rlimit *rlim)；
		resource：
			RLIMIT_AS：进程最大虚拟内存空间
			RLIMIT_CORE：内存转储文件的最大大小
			RLIMIT_CPU：使用CPU的最大时间
			RLIMIT_DATA：进程数据端的最大大小
			RLIMIT_STACK：进程堆栈大小
		struct rlimit{
			rlim_t rlim_cur;
			rlim_t rlim_max;
		}

扩展：
	1.针对每道题都设置一个定时器

【时间-日志等级 文件：行号】具体的日志信息
info，warning，error，fatal，debug
日志可以加到model模块，检测打开文件是否失败

Makefile：
	1.添加
		INCLUDE_PATH=............
		LIB_PATH=................
		BIN=../bin/svr
	2.然后在调用处：
		$(INCLUDE_PATH)
		$(LIB_PATH)
		$(BIN):oj_server
	3.清除
		.PHONY:clean
		clean:
			rm $(BIN)
如果不输入/all_questions，则默认访问逻辑根目录：index.html

html：网页内容
css：网页布局
js：网页动态计算

<title>：
<nav>：导航栏
ace
*/
/*
前端知识：
html页面：
<html>
	<head></head>		定义html页面的属性信息
		<meta></meta>	提供html页面元数据，这些元数据可以被浏览器识别，正文的类型
		<meta http-equiv="content-type" content="text/html;charset=utf-8">
			http-equiv：定义key
			content：定义value

	<body></body>		想在浏览器中展示的内容，文档主体
		{{#question}}{{question}}	
		<div></div>		在html页面中定义的分块
		<a></a>			超链接
			<a href="/question/{{id}}">{{id}}.{{title}}({{star}})</a>
		<form>			表单
		<action>		要执行的动作
</html>
*/

/*
int setrlimit(int resourse, const struct rlimit *rlim);
	resource：
		RLIMIT_AS：进程最大虚拟内存空间
		RLIMIT_CORE：
		RLIMIT_CPU：
		RLIMIT_DATA：
		RLIMIT_STACK：
	struct rlimit
	{
		rlim_t rlim_cur；软限制
		rlim_t rlim_max；硬限制
	}
日志信息：
	【20210123】
	info等级：warning，error，fatal，debug
	
enum Loglevel
{
	INFO = 0,		0
	WARNING,		1
	ERROR,			2
	FATAL,			3
	DEBUG			4
};
字符指针数组：分别指向枚举值的每一个下标
宏定义：__FILE__，__LINE__
int Log(LogLevel lev, const char* file, int line, const std::string& logmsg)
{
	
}















*/