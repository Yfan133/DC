#pragma once
#include <memory>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// auto_ptr��Ȩ��ת�ƣ�����ȫ
// unique_ptr����ֹ�����͸�ֵ
// shared_ptr�����Կ����͸�ֵ����һ�����ü���ȥ�����ж��ٸ�����
// weak_ptr�����shared_ptr��ѭ����������
template <class T>
class smartPtr
{
public:
	smartPtr(T* ptr)
		: _ptr(ptr)
	{
		// �����ʱ�򴴽�

	}
	~smartPtr()
	{
		// ������ʱ������
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}
	smartPtr(smartPtr<T>& sp)
		: _ptr(sp._ptr)
	{
		sp._ptr = nullptr;
	}
	smartPtr<T>& operator=(smartPtr<T>& sp)
	{
		if (this != &sp)
		{
			delete _ptr;
			_ptr = sp._ptr;
			sp._ptr = nullptr;
		}
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};
class Date
{
public:
	int _year = 1;
};
void Test1()
{
	smartPtr<int> sp(new int(1));
	smartPtr<int> sp1(new int(2));

	// ��������
	smartPtr<int> sp2(sp);
	// ��ֵ����
	sp1 = sp2;

	// ����ָ������ָ��Ĳ���
	smartPtr<Date> sp3(new Date);
	cout << (*sp3)._year << endl;
	cout << sp3->_year << endl;
}
void Test2()
{
	auto_ptr<Date> ap(new Date);
	cout << ap->_year << endl;
	// ����ʱ����Ȩ��ת��
	auto_ptr<Date> ap1(ap);
	cout << ap1->_year << endl;

	// ת��֮������ָ�벻��ӵ����Դ
	cout << ap->_year << endl;	// ���﷢������ָ��Ϊ��
}
void Test3()
{
	unique_ptr<Date> up(new Date);
	// unique_ptr<Date> up1(up);	// ���ﱻ��ֹ��,����������ɾ������
	unique_ptr<Date> up2(new Date);
	// up2 = up;	// ����Ҳ����ֹ�ˣ���ֵ������ɾ������
}
// ģ��ʵ�� unique_ptr
template <class T>
class Unique_ptr
{
public:
	Unique_ptr(T* ptr)
		: _ptr(ptr)
	{}
	~Unique_ptr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	// ��ֹ����
	Unique_ptr(const Unique_ptr<T>& up) = delete;
	Unique_ptr<T>& operator=(const Unique_ptr<T>& up) = delete;
private:
	T* _ptr;
};
void Test4()
{
	shared_ptr<Date> sp(new Date);
	cout << sp.use_count() << endl;
	shared_ptr<Date> sp1(sp);
	cout << sp.use_count() << endl;
	shared_ptr<Date> sp2(new Date);
	sp2 = sp;
	cout << sp.use_count() << endl;
}

#include <mutex>
// ģ��ʵ�� shared_ptr
template <class T>
class Shared_ptr
{
public:
	Shared_ptr(T* ptr)	// ���ﲻ����const��ԭ����ΪҪ��ptr��_ptr��ֵ����_ptr��T*���͡�
		: _ptr(ptr)
		, use_count(new int(1))
		, _mtx(new mutex)
	{}
	~Shared_ptr()
	{
		if (subRef() == 0)
		{
			delete _ptr;
			delete use_count;
			delete _mtx;
			use_count = nullptr;
			_ptr = nullptr;
		}
	}
	Shared_ptr(const Shared_ptr<T>& sp)
		: _ptr(sp._ptr)
		, use_count(sp.use_count)
		, _mtx(sp._mtx)
	{
		addRef();
	}
	Shared_ptr<T>& operator=(const Shared_ptr<T>& sp)
	{
		// if (this != &sp) ����Ӧ���ж�˫���������Դ�Ƿ���ͬ
		if (_ptr != sp._ptr)
		{
			if (subRef() == 0)	// �̰߳�ȫ�汾
			{
				delete _ptr;
				delete use_count;
				delete _mtx;
			}
			_ptr = sp._ptr;
			use_count = sp.use_count;
			_mtx = sp._mtx;
			addRef();
		}
		return *this;
	}
	int getUseCount()
	{
		return *use_count;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	int addRef()
	{
		_mtx->lock();
		++(*use_count);
		_mtx->unlock();
		return *use_count;
	}
	int subRef()
	{
		_mtx->lock();
		--(*use_count);
		_mtx->unlock();
		return *use_count;
	}
private:
	T* _ptr;
	int* use_count;
	mutex* _mtx;
};

void Test5()
{
	Shared_ptr<Date> sp1(new Date);
	Shared_ptr<Date> sp2(new Date);
	cout << sp1.getUseCount() << endl;
	Shared_ptr<Date> sp3(sp1);
	cout << sp1.getUseCount() << endl;
	sp2 = sp1;
	cout << sp1.getUseCount() << endl;
}
#include <thread>
void func(Shared_ptr<Date> sp, int n)
{
	for (int i = 0; i < n; i++)
	{
		Shared_ptr<Date> copy(sp);
	}
}
void TestThread()	// ��ʵ��ݴ����и����⣺��������
{
	Shared_ptr<Date> sp(new Date);
	cout << sp.getUseCount() << endl;
	int n;
	cin >> n;
	thread t1(func, sp, n);
	thread t2(func, sp, n);

	t1.join();
	t2.join();
	cout << sp.getUseCount() << endl;
}
template <class T>
struct ListNode
{
	~ListNode()
	{
		cout << "����" << endl;
	}
	shared_ptr<ListNode<T>> prev;
	shared_ptr<ListNode<T>> next;
};
void Test6()
{
	// �������ã��ҵ������ͷţ���������ͷţ�������ͷŲ�����Դ
	shared_ptr<ListNode<int>> sp(new ListNode<int>);
	shared_ptr<ListNode<int>> sp1(new ListNode<int>);
	cout << sp.use_count() << endl;
	cout << sp1.use_count() << endl;

	sp->prev = sp1;
	sp1->next = sp;

	cout << sp.use_count() << endl;
	cout << sp1.use_count() << endl;
}

template <class T>
struct ListNode2
{
	~ListNode2()
	{
		cout << "����" << endl;
	}
	weak_ptr<ListNode2<T>> prev;
	weak_ptr<ListNode2<T>> next;
};
void Test7()
{
	// ʹ��weak_ptr���ѭ����������
	shared_ptr<ListNode2<int>> sp(new ListNode2<int>);
	shared_ptr<ListNode2<int>> sp1(new ListNode2<int>);
	cout << sp.use_count() << endl;
	cout << sp1.use_count() << endl;

	sp->prev = sp1;
	sp1->next = sp;

	cout << sp.use_count() << endl;
	cout << sp1.use_count() << endl;
}

template <class T>
struct freeM
{
	void operator()(T* ptr)
	{
		free(ptr);
		cout << "free" << endl;
	}
};
void Test8()
{
	// ����ɾ������shared_ptr ֻ��ʹ��deleteɾ�����������malloc����new[]����Ҫ����ɾ����
	freeM<int> fm;
	shared_ptr<int> sp((int*)malloc(sizeof(int)));
}