#pragma once
/*
前提：
////////////////////////////////////////////////////////////////////////////////////////////
RPC可以给我们提供一种类似本地调用一样方便的远程网络服务
	本地调用：方法实现都在本地
	远程调用：方法实现和执行过程都在远端
SSH：也有点像RPC，XSHELL上的命令发送到Linux中，然后返回执行完的信息

课后调研常见rpc框架：REST_RPC、sofa-pbrpc、
rpc底层使用了bost的网络框架，(C++)bost解决了网络问题，REST_RPC解决RPC问题，我们只关心游戏
///////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////
游戏客户端：1.注册、登录、匹配、game
具体实现：
	1.git clone 源代码，把文件名修改成Gobang，只留下examples、include、third。
	2.examples和include：只留main.cpp和CMAKE.txt
	
	安装：cmake
	CMakeLists.txt：可自动生成makefile
	使用 cmake ../
	
	gcc -v 查看gcc的版本
	自动使用最高版本的gcc
		1.vim ~/.bashrc
		2.source scl_source enable devtoolset-7

完善并裁剪代码：
	vs main.cpp
	
改进：
1.使用函数指针数组加下标的方式，代替switch case
2.密码优化
3.好友系统





































*/