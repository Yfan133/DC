#pragma once
//ģ��ʵ��STL��string
//Ϊʲô���������[]��ҪŪ��һ��const
//namespace bit
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//		//����
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
//		//������
//		iterator begin()						//s1.begin()���ص����ַ�����ʼλ��
//		{
//			return _str;
//		}
//		iterator end()						//s1.end()���ص�λ�����ַ���������'\0'���ڵ�λ��
//		{
//			return _str + _size;
//		}
//		//////////////////////////////////////////////////
//		//����
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
//				char* tmp = new char[n];		//���ϴ����ģ��ں����������ᱻ�ͷţ�����ڴ�й¶һ�㶼�Ǻ����ڶ�̬����δ�����ͷŵ�
//				strcpy(tmp, _str);
//				delete[] _str;
//				_str = tmp;
//				_capacity = n;
//			}
//		}
//		/////////////////////////////////////////////////////////////
//		//Ԫ�ط���
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
//		//�޸�
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
//			//if(_capacity<_size)			//Ϊʲô������������һֱpush_back���������Ϊԭ�ռ䱻�ͷ��ˣ������µĿռ䣬�µ�capacity
//			_capacity = _size;
//			return *this;
//		}
//		string& operator+=(const string& tmp)
//		{
//			*this += tmp._str;				//strcat������ֱ�ӽ������ĵ�ַ���ӵ�һ�𣬶��ǰ�char* str2��һ����������str1����ȥ�����str1Ҫ���㹻�Ŀռ�
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
//		string& clear()					//��գ�ֻ��Ҫ����ЧԪ�صĸ�����0��������_str[0]='\0'
//		{
//			_size = 0;
//			_str[0] = '\0';
//		}
//		///////////////////////////////////////////////////////////////////
//		///�������
//		const char* c_str()const		//����ֱ�ӷ��ص�_str�ĵ�ַ����˲��������ַ���൱�ڲ���string �ַ���
//		{
//			return _str;
//		}
//		size_t find(char ch, size_t pos = 0)				//����
//		{
//			while (pos < _size)
//			{
//				if (_str[pos] == ch)
//					return pos;
//				pos++;
//			}
//			return npos;
//		}
//		size_t rfind(char ch, size_t pos = npos)			//������ң�������pos����posĬ�ϵ�����Ϊnpos
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
//		string substr(size_t pos, size_t n = npos)	//������ˣ��Ǵ�pos��ʼ��ȡn���ַ�
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