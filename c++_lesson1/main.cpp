#include"main.h"
//thisָ����������ڱȺ���Ҫ��

//template<class T>
//class Seqlist
//{
//public:
//	Seqlist(int capacity)				//����
//		:_base(new T[capacity])
//		,_capacity(capacity)
//		,_size(0)
//	{}
//	Seqlist(const Seqlist<T>& tmp);		//��������
//	~Seqlist()
//	{
//		delete[] _base;
//		_capacity = 0;
//		_size = 0;
//	}
//	Seqlist<T>& operator=(const Seqlist<T>& tmp)	//��ֵ���������
//	{}
//	T& operator[](int data)
//	{
//		return _base[data];
//	}
//	const T& operator[](const T data)const					//������[]���أ�base[n]�ĺ���
//	{
//		return _base[data];
//	}
//	void SeqPush(const T data)				//β��
//	{
//		_base[_size] = data;
//		_size++;
//	}
//private:
//	T* _base;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	Seqlist<int> s1(10);
//	s1.SeqPush(1);
//	s1.SeqPush(2);
//	s1.SeqPush(3);
//	s1.SeqPush(4);
//	cout << s1[2] << endl;
//	return 0;
//}
#include<string>
int main()
{
	string a("hello world");
	a.resize(15, 'p');
	a.resize(10, 'p');
	a.resize(5);
	a.reserve(15);
	a.reserve(5);
	a.erase(a.begin(), a.begin() + 3);
	//Ϊʲô������û�м�С����
	return 0;
}
