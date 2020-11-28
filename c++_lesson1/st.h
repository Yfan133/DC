#pragma once
//模拟实现STL的string
//为什么重载运算符[]，要弄出一个const
//namespace bit
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//		//构造
//		string(const char* ptr = "")
//		{
//			if (ptr == nullptr)
//				ptr = "";
//			_size = strlen(ptr);
//			_capacity = _size;
//			_str = new char[_capacity + 1];
//			strcpy(_str, ptr);
//		}
//		string(size_t n, char ch)
//			: _str(new char[n + 1])
//			, _size(n)
//			, _capacity(n)
//		{
//			memset(_str, n, ch);
//			_str[_size] = '\0';
//		}
//		template<class iterator>
//		string(iterator first, iterator last)
//		{
//			auto it = first;
//			size_t count = 0;
//			while (it != last)
//			{
//				count++;
//				it++;
//			}
//			it = first;
//			_size = _capacity = count;
//			_str = new char[_capacity + 1];
//			for(size_t i=0;i<_size;i++)
//			{
//				_str[i] = *it++;
//			}
//			_str[_size] = '\0';
//		}
//		string(const string& tmp)
//			:_str(new char[strlen(tmp._str)+1])
//			,_size(tmp._size)
//			,_capacity(tmp._capacity)
//		{
//			strcpy(_str, tmp._str);
//		}
//		~string()
//		{
//			if (_str)
//			{
//				delete[] _str;
//				_size = 0;
//				_capacity = 0;
//			}
//		}
//		string& operator=(const string& tmp)
//		{
//			if (this != &tmp)
//			{
//				delete[] _str;
//				new char[strlen(tmp._str) + 1];
//				strcpy(_str, tmp._str);
//				_size = tmp._size;
//				_capacity = tmp._capacity;
//			}
//			return *this;
//		}
//		///////////////////////////////////////////////////
//		//迭代器
//		iterator begin()						//s1.begin()返回的是字符串起始位置
//		{
//			return _str;
//		}
//		iterator end()						//s1.end()返回的位置是字符串最后面的'\0'所在的位置
//		{
//			return _str + _size;
//		}
//		//////////////////////////////////////////////////
//		//容量
//		size_t size()
//		{
//			return _size;
//		}
//		size_t capacity()
//		{
//			return _capacity;
//		}
//		bool empty()
//		{
//			return 0 == _size;
//		}
//		void resize(size_t n, char ch)
//		{
//			if (n > _size)
//			{
//				if (n > _capacity)
//				{
//					reserve(n);
//				}
//				memset(_str + _size, ch, n - _size);
//			}
//			_size = n;
//		}
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n];		//堆上创建的，在函数结束不会被释放，因此内存泄露一般都是函数内动态申请未主动释放的
//				strcpy(tmp, _str);
//				delete[] _str;
//				_str = tmp;
//				_capacity = n;
//			}
//		}
//		/////////////////////////////////////////////////////////////
//		//元素访问
//		char& operator[](int index) 
//		{
//			assert(index < _size);
//			return _str[index];
//		}
//		const char& operator[](int index)const
//		{
//			assert(index < _size);
//			return _str[index];
//		}
//		////////////////////////////////////////////////////////////
//		//修改
//		void push_back(char ch)
//		{
//			if (_capacity == 0)
//				reserve(15);
//			else if (_size == _capacity)
//				reserve(_capacity * 2);
//			_str[_size++] = ch;
//			_str[_size] = '\0';
//		}
//		string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//		string& operator+=(const char* ptr)
//		{
//			int len = strlen(ptr);
//			char* tmp = new char[_size + len + 1];
//			strcpy(tmp, _str);
//			strcat(tmp + _size, ptr);
//			delete[] _str;
//			_str = tmp;
//			_size += len;
//			//if(_capacity<_size)			//为什么这样做，遇到一直push_back会崩溃，因为原空间被释放了，这是新的空间，新的capacity
//			_capacity = _size;
//			return *this;
//		}
//		string& operator+=(const string& tmp)
//		{
//			*this += tmp._str;				//strcat并不是直接将两个的地址连接到一起，而是把char* str2的一个个拷贝到str1里面去，因此str1要有足够的空间
//			return *this;
//			/*int len = tmp._size;
//			char* ptr1 = new char[_size + len + 1];
//			strcpy(ptr1, _str);
//			char* ptr2 = new char[len + 1];
//			strcpy(ptr2, tmp._str);
//			strcat(ptr1 + _size, ptr2);
//			_size += len;
//			_capacity = _size;
//			return *this;*/
//		}
//		string& insert(int pos, const char* ch)
//		{
//			int len = strlen(ch);
//			char* tmp = (char*)malloc(_size + len + 1);
//			strcpy(tmp, _str);
//			strcpy(tmp + pos, ch);
//			strcpy(tmp + pos + len, _str + pos);
//			_size += len;
//			_capacity = _size;
//			delete[] _str;
//			_str = tmp;
//			return *this;
//		}
//		iterator erase(iterator pos)
//		{
//
//		}
//		string& clear()					//清空，只需要将有效元素的个数清0，并且让_str[0]='\0'
//		{
//			_size = 0;
//			_str[0] = '\0';
//		}
//		///////////////////////////////////////////////////////////////////
//		///特殊操作
//		const char* c_str()const		//这里直接返回的_str的地址，因此操作这个地址就相当于操作string 字符串
//		{
//			return _str;
//		}
//		size_t find(char ch, size_t pos = 0)				//查找
//		{
//			while (pos < _size)
//			{
//				if (_str[pos] == ch)
//					return pos;
//				pos++;
//			}
//			return npos;
//		}
//		size_t rfind(char ch, size_t pos = npos)			//反向查找，若不传pos，则pos默认的属性为npos
//		{
//			int cur = pos == npos ? _size - 1 : pos;
//			while (cur >= 0)
//			{
//				if (_str[cur] == ch)
//					return cur;
//				cur--;
//			}
//			return npos;
//		}
//		string substr(size_t pos, size_t n = npos)	//这里错了，是从pos开始截取n个字符
//		{
//			n = n == npos ? _size : n;
//			string s;
//			while (pos <= n)
//				s.push_back(_str[pos++]);
//			return s;
//		}
//	private: 
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//		static size_t npos;
//	};
//	size_t string::npos = -1;
//}