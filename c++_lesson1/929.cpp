#include"main.h"
//ÿ����Ա�����ж�����һ��thisָ�룬ָ��ǰ����ĵ�ַ����thisָ�벻�ܸ�ֵ
/*
���ƣ� void Test(student* ps,char name[],char gender[],int age)
this�滻��ps������
ps->_name=name;
this->_name=name;
��д��_name=name;
this��*const��������޷��ı�ָ��
thisָ����Ҫͨ����ecx���Ĵ������ݣ�leaȡ��ַ
��ѯ�����õ���Լ��
add x---��thisָ��ĵ�ַ����x
*/

class student
{
	char name[20];
	char gender[3];
	int age;
};
class A			//���м��г�Ա���������г�Ա����
{
	int a;
	void f1()
	{}
};
class B			//����ֻ�г�Ա����
{
	void Test_B()
	{}
};
class C			//����
{};
struct D		//�սṹ��
{};
int main()
{
	C c1, c2, c3;
	cout << &c1 << endl << &c2 << endl << &c3;
	return 0;
}

//ʲô�ǽṹ���ڴ���룿Ϊʲô��Ҫ�ڴ���룿
//Ĭ�϶����������ζ������ã�Ĭ�϶������ÿ�������Ϊ����ֵ��
//��ô��ṹ���ڳ�Ա��������ʼƫ������offsetof(AA.c)ģ��ʵ�֣��ٶȱ����⣩
//ʲô�Ǵ�С�ˣ�дһ�������жϻ����Ĵ�С�ˣ������ַ�����˵һ���龰Ҫ���Ǵ�С�����⡣��С�˺Ͳ���ϵͳ��û�й�ϵ
//#pragma pack(4)
//#pragma pack()�ָ�Ĭ��ֵ
