#include"main.h"
//thisָ����������ڱȺ���Ҫ��

//template<class T>
//class Seqlist
//{
//public:
//	Seqlist(int capacity = 5)				//����
//		:_base(new T[capacity])
//		, _capacity(capacity)
//		, _size(0)
//	{}
//	Seqlist(const Seqlist<T>& tmp)			//��������
//	{}		
//	~Seqlist();								//�������������ⶨ��
//	Seqlist<T>& operator=(const Seqlist<T>& tmp)	//��ֵ���������
//	{}
//	T& operator[](int data)							//������[]���أ�base[n]�ĺ���
//	{
//		assert(data < _size);
//		return _base[data];
//	}
//	void SeqPush(const T data)						//β��
//	{
//		_base[_size] = data;
//		_size++;
//	}
//	void SeqPopBack()
//	{
//		_size--;
//	}
//	int SeqSize()
//	{
//		return _size;
//	}
//private:
//	T* _base;
//	int _size;
//	int _capacity;
//};
//template<class T>
//Seqlist<T>::~Seqlist()	//������ʵ�ֶ���ĺ�������Ҫ��ģ������б�
//{
//	if (_base)
//	{
//		delete[] _base;
//		_capacity = 0;
//		_size = 0;
//	}
//}
//int main()
//{
//	Seqlist<int> s1(10);
//	Seqlist<double>s2(10);
//	s1.SeqPush(1);
//	s2.SeqPush(1.0);
//	return 0;
//}
int main()
{
	string s1("asdfc");
	char* p = (char*)s1.c_str();
	*p = 'p';
	cout << s1.rfind('c');
	printf("%d", sizeof(s1));
	s1.clear();
	string s2 = "ABCD";
	string s3(10, 'a');
	string s4(s1);
	string s5 = s1;
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
	cout << s1.empty() << endl;
	cout << s1.size() << endl;
	return 0;
}

//#include<string>
//int main()
//{
//	string a("hello world");
//	a.resize(15, 'p');
//	a.resize(10, 'p');
//	a.resize(5);
//	a.reserve(15);
//	a.reserve(5);
//	a.erase(a.begin(), a.begin() + 3);
//	//Ϊʲô������û�м�С����
//	return 0;
//}
