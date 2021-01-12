#pragma once
/*
面试系统
	1.目的：方便学校或者机构来和用户预约一个面试时间
	2.使用的技术：
		http协议(tcp协议)、json数据格式、mysql-c开发包(连接mysql数据库，增删改查)
	3.需要安装的环境
		1.jsoncpp
			yum -y install epel-release
			yum -y install jsoncpp-devel
		2.mysql客户端开发环境
			mariadb(mysql)
			yum -y install mariadb-devel
		3.mariasb数据库

		4.mysql数据库的
			yum list | grep mysql-devel
	4.需求：
		1.能够支持客户注册
		2.能够支持客户登录
		3.能够支持客户预约
	5.整体架构
		C/S --》client 和 sever
		B/S --》浏览器 + 服务端
	chrome
	http请求接收
	注册模块



*/