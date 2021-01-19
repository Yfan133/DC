/*
目标：仿照leetcode的界面功能
	1.查看题目列表
	2.点击题目跳转
	3.支持书写代码并提交运行
	4.返还运行结果
环境搭建：
	1.cpp-httplib开源库：
		使用方法：直接包含头文件就可以了：include "httplib.h"
	2.升级GCC：
		1.下载高版本gcc：bash中输入以下命令
			sudo yum -y install centos-release-scl
			sudo yum -y install devtoolset-7-gcc devtoolset-7-gcc-c++ devtoolset-7-binutils
		2.设置默认启动高版本gcc
			打开文件
				vim ~/.bash_profile
			在最后添加：
				scl enable devtoolset-7 bash
			重启gcc
				source ~/.bash_profile
	3.下载jsoncpp
		yum install jsoncpp
		yun install jsoncpp-devel
	4.下载cpp-httplib库
		打开码云中cpp-httplib链接，下载httplib.h头文件	
	5.下载boost环境，ctemplate
		sudo yum install -y snappy-devel boost-devel zlib-devel.x86_64 python-pip
		sudo pip install BeautifulSoup4
		git clone https://gitee.com/HGtz2222/ThirdPartLibForCpp.git
		cd ./ThirdPartLibForCpp/el7.x86_64/
		sh install.sh

httplib库介绍：可以帮助我们创建一个http服务，不需要关心tcp和http的解析过程，解析完http请求之后，会按照请求的方法，找到对应注册的回调函数进行处理
	Server类的回调函数：
		1.函数名就是当前注册的回调函数的方法
			举个例子：
			Get方法：
				Server &Get(const char *pattern, Handler handler);
					pattern：注册的url资源路径(浏览器请求路径要和注册的一致才能回调handler)
					handler：函数指针
						using Handler = std::function<void(const Request &, Response &)>;
						Request:http请求的内容
						Response:回复给浏览器的响应
			Response结构体：
				get_header_value()：响应包头
				set_header()：设置key:value形式的响应包头
				set_redirect()：重定向
				set_content()：设置响应体：body，一种是c风格，一种是C++风格
测试httplib-demo
	前提：关闭Linux防火墙
	用chorm浏览器访问  ip:端口号/路径

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

λ表达式：[](){}：[]：λ传递的参数 ()：参数列表 {}：处理机制
*/
/*
code目录下的模块
	oj_data：文件信息
		1.oj_config_cfg：题目总览
		2.每个题目的详细信息
			1.desc.txt：题目描述信息
			2.header.cpp：头文件和Solution
			3.tail.cpp：调用用户的代码
	oj_model.hpp：获取文件信息
		1.文件结构体：文件的各种信息
		2.类Model：
			1.打开oj_文件，并获取所有文件的总览
			2.通过路径，获取每道题的详细信息
			3.返回给上层 vector<Questions> 集合
			
			GetOneQues()：获取一个试题
				
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
			2.服务端
				1.正则表达式通配url中的题号
				2.对提交的代码进行url解码
				
				

	tools.hpp：打开文件返回文件内容，切分字符串
		1.split
		2.
	template：html的模板
	oj_view.hpp：用代码填充html的模板
		/////1.把template加到环境变量中：
		1.创建一个TemplateDictionary类对象，构造要填充name
		2.遍历vector<>填充好字典，看下setvalue函数
		3.填充html页面，先Get页面，再Expand填充字典数据
	问题：看一下oj_view.hpp的出参是什么？












试题信息获取：oj_model.hpp
	1.题目的描述：结构体questions
		1.题目id
		2.题目标题
		3.题目难易程度
		4.题目路径
		5.题目描述
		6.预定义头文件
		7.题目的测试用例、调用逻辑Solution
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

所有题目信息:oj_data
	工具模块：从文件中读取

注意：
	getline是以\n来区分的，因此我们在后面加\n
	用static修饰的函数，不用实例化对象直接，类::函数进行调用

前端知识：
html页面：
<html>
<head></head>	定义属性信息，
<body></body>	想展示的内容，文档主体
<div></div>		分块
<a></a>			超链接
<meta>			提供html页面源数据，正文的类型
</html>

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

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string id1 = "1";
	string id2 = "123";
	if (id1 < id2)
		cout << "yes" << endl;
	return 0;
}