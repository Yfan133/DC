#include<iostream>
#include<assert.h>
using namespace std;
namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		//构造
		vector()	//无参构造
			:start_(nullptr)
			, finish_(nullptr)
			, end_of_storage_(nullptr)
		{}
		vector(int SIZE, const T& Data = T())	//容量构造,这里模板默认值是0
			:start_(new T[SIZE])
			, finish_(start_ + SIZE)
			, end_of_storage_(finish_)
		{
			for (int i = 0; i < SIZE; i++)
				start_[i] = Data;
		}
		template<class Iterator>	//这里为什么重新定义了一个模板
		vector(Iterator begin, Iterator end)	//迭代器构造
		{
			int size = end - begin;
			start_ = new T[size];
			for (int i = 0; i < size; i++)
			{
				start_[i] = begin[i];
			}
			finish_ = start_ + size;
			end_of_storage_ = finish_;
		}
		vector(const vector<T>& v)	//拷贝构造
		{
			size_t size = v.finish_ - v.start_;		//尽量用无符号整型表示
			start_ = new T[size];
			for (int i = 0; i < size; i++)
			{
				start_[i] = v.start_[i];
			}
			finish_ = start_ + size;
			end_of_storage_ = finish_;
		}
		~vector()
		{
			if (start_)		//这里一定要先判断一下是否为空
			{
				delete[] start_;
				start_ = finish_ = end_of_storage_ = nullptr;
			}
		}

		///迭代器操作///
		iterator begin()
		{
			return start_;
		}
		iterator end()
		{
			return finish_;
		}
		typedef const T* const_iterator;
		const_iterator cbegin()
		{
			return finish_;
		}
		const_iterator cend()const
		{
			return start_;
		}
		//容量
		size_t size()const
		{
			return finish_ - start_;
		}
		size_t capacity()const
		{
			return end_of_storage_ - start_;
		}
		bool empty()
		{
			return start_ == finish_;
		}
		void reserve(size_t n)	//扩容
		{
			if (n > capacity())
			{
				T* it = new T[n];
				size_t old = size();
				//memcpy(it,start_,size*sizeof(T));为什么这里不能用memcpy
				for (int i = 0; i < old; i++)
					it[i] = start_[i];
				delete[] start_;
				start_ = it;
				finish_ = start_ + old;
				end_of_storage_ = start_ + n;
			}
		}
		void resize(size_t n, T Data = T())
		{
			int old = size();
			if (n > old)
			{
				if (n > capacity())
					reserve(n);
				for (int i = old; i < size(); i++)
					start_[i] = Data;
			}
			finish_ = start_ + n;
		}
		/////随机访问/////
		T& operator[](size_t pos)		
		{
			assert(pos < size());
			return start_[pos];
		}
		const T& operator[](size_t pos)const
		{
			assert(pos < size());
			return start_[pos];
		}
		/////元素操作/////
		void push_back(const T& Data)
		{
			if (finish_ == end_of_storage_)
				reserve(capacity() * 2 + 3);
			*finish_++ = Data;
		}
		void pop_back()
		{
			if (empty())
				return;
			--finish_;
		}
		/*void swap(vector<T>& v) 
		{
			swap(start_, v.start_);
			swap(finish_, v.finish_);
			swap(end_of_storage_, v.end_of_storage_);
		}*/
		void swap(vector<T>& v)
		{
			Swap(&start_, &v.start_);
			Swap(&finish_, &v.finish_);
			Swap(&end_of_storage_, &v.end_of_storage_);
		}
		iterator insert(iterator pos, const T& Data)		//这里插入，一次只能插入一个元素，而且必须带const，不然传常量时报错
		{
			assert(pos <= end());
			if (finish_ == end_of_storage_)
				reserve(capacity() * 2 + 3);
			iterator it = end();
			while (it != pos)
			{
				*it = *(it - 1);
				--it;
			}
			*it = Data;
			++finish_;
			return pos;
		}
		iterator erase(iterator pos)		//删除只能删除迭代器位置的元素
		{
			assert(pos < finish_);
			
			iterator it = pos;
			while (it < finish_ - 1)
			{
				*it = *(it + 1);
				++it;
			}
			--finish_;
			return pos;
		}
	private:
		void Swap(iterator* it1, iterator* it2)
		{
			iterator tem = *it1;
			*it1 = *it2;
			*it2 = tem;
		}
	private:
		iterator start_;
		iterator finish_;
		iterator end_of_storage_;
	};
}

