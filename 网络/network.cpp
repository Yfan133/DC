/*
网络：网络基础1  网络套接字  网络基础2   网络基础3  高级IO

网络基础1：
	背景：
		网络的任务：信息共享，信息交换
		画个图：家网络到城网络
		按返回划分：局域网：几公里  城域网：几十公里  广域网：几百公里  
		长城防火墙：我国的广域网
		Transfer Pacific Cable：太平洋光缆，从青岛上岸
	网络协议：
		协议：国家事务或者外交场合的正式程序或者规则系统
		画个图：两国友人交流
		协议：通信双方对于通信进行约定，使用一种共同语言来进行有效沟通；
		网络协议：在网络当中通信双方对数据交换和数据传输做出决定
		计算机当中有很多网络协议，将这些网络协议联系在一起，称之为协议簇(TCP/IP)
		参考模型或者体系结构：在协议簇当中，定义各个协议之间的相互关系和协议需要完成的任务
		
	协议分层：
		协议分层就是一种封装，对不同的协议或者服务进行封装
		OSI参考模型(参考意义，实际工业上是没有使用的，分层太细)
		口诀：物数网传会表应
		物理层，数据链路层，网络层，传输层，会话层，表示层，应用层
		前面6层已经被实现了，我们只关心应用层
	TCP/IP五层模型
		物理层，数据链路层，网络层，传输层，应用层(合并会话层，表示层)
	
	计算机网络当中两台计算机如何进行通信
		IP地址：在网络当中唯一标识一台主机
		PORT：端口在一台主机上标识一个进程
	1.应用层：负责应用层程序之间的数据传输，程序员就是工作在这一层面的
		典型的协议：HTTP协议，FTP协议，DNS协议，SMTP协议
	2.传输层：负责端与端之间的数据传输，理解端与端是知道是端口和端口之间传输
		典型协议：TCP协议和UDP协议
	3.网络层：负责路由选择和地址管理
		典型协议：IP协议，ARP协议，ICMP协议
		典型设备：路由器
	4.数据链路层：负责相邻设备之间的数据帧传输
		典型协议：以太网协议(Ethernet)
		典型设备：交换机
	5.物理层：负责光电信号的传输
		典型协议：以太网协议
		典型设备：集线器







	网络传输流程：
	网络地址管理：

















*/