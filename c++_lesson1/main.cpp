

// ���ȼ����в���
//int main()
//{
//	vector<int> arr = { 1,2,3,6,8,10 };
//	Test1();
//	Test2();
//	//sort(arr.begin(), arr.end(), [](int a, int b) {return a > b; });
//	return 0;
//}

// ���ȼ�����ģ��ʵ��
//int main()
//{
//	TestMyPriorityQueue1();
//	TestMyPriorityQueue2();
//	return 0;
//}

// ����ָ��ģ��ʵ��
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

// ��ɢ��ģ��ʵ��
//#include "hashTable.h"
//int main()
//{
//	TestHt();
//	return 0;
//}

// ��ɢ��ģ��ʵ��
//#include "hashTable2.h"
//int main()
//{
//	HashTable<int, int, KofV<int>> ht;
//
//	ht.Insert(10);
//	ht.Insert(7);
//	ht.Insert(35);
//	ht.Insert(12);
//	ht.Insert(25);
//	ht.Insert(4);
//	ht.Insert(14);
//	ht.Insert(11);
//	ht.Insert(9);
//
//	HashNode<int>* cur = ht.find(12);
//	cout << cur << endl;
//	cur = ht.find(100);
//	cout << cur << endl;
//
//	bool ret = ht.erase(12);
//	ret = ht.erase(100);
//	ret = ht.erase(25);
//	return 0;
//}
#include <iostream>
using namespace std;
class A
{
public:

	static int a;
};
int A::a = 1;
int main()
{
	

	return 0;
}
/*
1.����ǿת
	ǿת�������ͻ�������ʱ������ǿת��ַ����������ʱ������
	��Ϊǿת�˵�ַ��ֻ��ָ������ַ����ʲô��ʽ���н���
2.this���ͣ�type* const��this����Ϊ�գ����������Ա�����е����˳�Ա�������߳�Ա������������
3.�����ڹ��캯����ʼ���б���г�ʼ���ģ�
	const��Ա����
	����
	�Զ������͵ĳ�Ա����(���ڲ���ȫȱʡ�����޲ι���)
4.const ���εĶ���ֻ�ܵ���const���εĳ�Ա����
  const ���εĳ�Ա����������ֻ�ܵ���const���εĳ�Ա����
5.C���Ե����ͺ�������ʾ��Χ
	char			-128~127
	short			-2^15~2~15-1
	int				-2^31~2^31-1
	long			
	long long
	float
	double
6.static���ε�
	��Ա������

	��Ա����

	C�����еģ�
	������
	ȫ�ֱ�����
	�ֲ�������
7.�������Ĵ洢
	�����Ƶı�׼��ѧ��������M һ���� 1.xxx����˲���Ҫ��1��ֻ��Ҫ������ XXX
	�м��� 127����+127��ȡ-127����ָ��λE��
		ע�⣺ָ��EΪ0����������Ϊ0(�涨����)
	����������ֵ����Ψһ�ģ�ͨ����ʾһ������,��f < MIN && f > -MIN��

*/