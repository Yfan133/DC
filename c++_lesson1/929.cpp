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
//#pragma pack(4)
class  Student
{
public:
	// ��Ա����
	char _name[20];
	char _gender[3];
	int _age;
public:
	// ��Ա����
	// �������ú���������������ʵ������4������
	// ����һ�������ǣ����ص�thisָ��
	// ��д�����ڼ䣬�û�������ʽ����thisָ�룬�������ڱ������ʱ�����Զ�����thisָ��Ĳ���
	void InitStudent(char name[],char gender[], int age)
	{
	//	// ���ܸ�thisָ�������и�ֵ----Student* const this
	//	//                          ������* const
	//	//this = nullptr;

	//	cout << this << endl;

	//	// ����thisָ�룬��Ա������֪���������ڲ����Ǹ�����
	//	// ע�⣺�Գ�Ա�����Ĳ�������ͨ��thisָ�������е�
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}
	// ע�⣺��Ա������������ڲ�����ж��壬��Ա�������ܻᱻ���������������������Դ�
	void PrintStudent()
	{
		cout << this << endl;
		cout << _name << "-" << _gender << "-" << _age << endl;
	}
	void SetAge(int age)
	{
		cout << this << endl;
		_age = age;
	}
};


int main()
{
	Student s1, s2, s3;
	s1.InitStudent("Peter", "��", 18);
	s2.InitStudent("David", "��", 19);
	s3.InitStudent("Lily", "Ů", 18);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();

	cout << sizeof(s1) << endl;
	return 0;
}
//ʲô�ǽṹ���ڴ���룿Ϊʲô��Ҫ�ڴ���룿
//Ϊ����߳������ܣ����ݽṹ(������ջ)���ڴ��ж��롣δ������ڴ洦����Ҫ�������Σ�������ڴ����һ��
//Ĭ�϶����������ζ������ã�Ĭ�϶������ÿ�������Ϊ����ֵ��
//vs:8�ֽ�       #prgma pack(4)     �������ó�2��n�η�
//��ô��ṹ���ڳ�Ա��������ʼƫ������offsetof(AA.c)ģ��ʵ�֣��ٶȱ����⣩
//
//ʲô�Ǵ�С�ˣ�дһ�������жϻ����Ĵ�С�ˣ������ַ�����˵һ���龰Ҫ���Ǵ�С�����⡣��С�˺Ͳ���ϵͳ��û�й�ϵ
//#pragma pack(4)
//#pragma pack()�ָ�Ĭ��ֵ
