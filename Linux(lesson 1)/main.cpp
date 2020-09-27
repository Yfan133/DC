#include<iostream>
//Linux不以文件后缀区分，加后缀和颜色是为用户区分
//环境变量:就是一个变量,用于存储系统运行的环境参数
//操作指令:env set echo 查看环境变量 export 设置环境变量 unset 删除环境变量
//作用:
//1)通过修改环境变量的值,灵活的配置系统运行参数
//2)子进程会继承父进程的环境变量

///////////////////////////////////////////////////////////
//程序地址空间
//地址:内存地址---对内存以字节为存储单元的一个编号
//
/*
内核空间
环境变量,运行参数
栈(往下生长)
...
...(共享区)
堆(往上生长)
未初始化全局
初始化全局
代码段
*/
//虚拟内存地址空间:可以提高物理内存利用率,虚拟内存是连续的,但实际上在物理内存中是离散存储的
//操作系统的内存管理方式:

/*
分段式:
通过段号查到物理内存地址,再用内存地址+段内偏移量找到对应的物理内存单元
未解决内存利用率低的问题
分页式:
通过页号查到该页号的物理内存地址,再用物理内存地址+页内偏移量()找到对应的物理内存单元
优点:内存块大小跟内存页一样,物理内存块比较小,并且不要求同一进程的多个数据必须在同一个块内,因此分页式实现了数据在物理内存中的离散式存储,提高了内存利用率
页表会在进行内存访问时会进行内存访问权限查询(页表和)
12412
32位操作系统 内存4G/4k == 页表项(页号)的个数 == 2^20 
段页式:

*/
//操作系统中,虚拟内存地址和物理内存地址有一个
/////////////////////////////////////////////////////////////////////
//写时拷贝技术：子进程创建出来之后，与父进程映射访问同一物理内存，当物理内存中数据即将发生改变时(父进程数据发生改变)
//重新为子进程开辟物理内存，拷贝数据过去。好处：防止给子进程创建空间，但子进程不用，降低了进程的创建效率，造成内存冗余数据
//pid_t vfork(void)  会造成死循环(vfork创建的子进程，不能在main函数中使用return退出，因为子进程使用return退出时释放了
//所有资源,父进程运行的时候资源是错误的)


//当父进程在main函数中调用fork函数创建子进程，fork运行完毕之后，父进程应该从调用fork函数的下一步开始执行
//fork父子进程各有各的栈，vfork父子进程共用同一块栈区
//printf打印数据，实际上是把数据交给显示器，让显示器显示。先放入数据缓冲区，等积累到一定数量之后一次性输出，这样做会提高程序运行效率。
//(\n)除了换行的作用之外，还有刷新缓冲区的作用（使数据输出）
//总之vfork父子进程同一空间，fork父子进程不同空间

//进程等待：父进程等待子进程退出，为了获取退出子进程返回值，释放退出子进程的所有资源
