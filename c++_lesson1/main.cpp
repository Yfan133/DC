#include<iostream>
#include<string>
using namespace std;
#pragma warning (disable:4996)
int main()
{
	//����
	string ar0;		//�޲ι��죬�����ַ���
	string ar1("qwer");	//��C_string����
	string ar2(5, 'w');	//n����ЧԪ�أ�ÿһ�������ַ�'w'
	string ar3(ar1);	//��������
	//����
	size_t size_ = ar1.size();		//������ЧԪ�ظ���
	size_t lenth_ = ar1.length();	//Ч����sizeһ��
	size_t capacity_ = ar1.capacity();	//��������
	ar1.empty();	//�ж��Ƿ�Ϊ��
	ar1.resize(10, 'a');	//����ЧԪ���޸�Ϊ10���������'a'�����
	ar1.reserve(100);		//����������Ϊ20����С��ԭʼ��������������
	ar1.clear();			//�����Ч�ַ���
	//��ʹ��string֮ǰ��������reserve���������úã�����ÿ�β������ݴ����Ŀ���
	capacity_ = ar0.capacity();
	for (int i = 0; i < 100; i++)
	{
		ar0.push_back('a');
		if (capacity_ != ar0.capacity())
		{
			capacity_ = ar0.capacity();
			cout << capacity_ << endl;
		}
	}

	return 0;
}
//#include"vc.h"
//int main()
//{
//	bit::vector<int> v0;
//	bit::vector<int> v1(5);
//	bit::vector<int> v2(v1.begin(), v1.end());
//	bit::vector<int> v3(v1);
//	v0.push_back(1);
//	v0.push_back(2);
//	v0.push_back(3);
//	v0.push_back(5);
//	v0.pop_back();
//	v0.swap(v1);
//	v0.insert(v0.begin(), 99);
//	v0.erase(v0.begin());
//	return 0;
//}