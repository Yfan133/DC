#pragma once
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
//	{
//		_capacity = tmp._capacity;
//		_base = new T[_capacity];
//		for (int i = 0; i < tmp._size; i++)
//		{
//			_base[i] = tmp._base[i];
//		}
//		_size = tmp._size;
//	}		
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
//	s1.SeqPush(2);
//	s1.SeqPush(2);
//	s1.SeqPush(2);
//	Seqlist<int> s3 = s1;
//	s2.SeqPush(1.0);
//	Seqlist<double>s4 = s2;
//	return 0;
//}