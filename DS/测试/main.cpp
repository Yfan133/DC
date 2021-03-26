//#include <iostream>
//#include <vector>
//using namespace std;
//class Sort
//{
//public:
//    static int Quick2(vector<int>& arr, int left, int right)
//    {
//        int key = arr[left];
//        while (left < right)
//        {
//            while (left < right && arr[right] >= key)
//                right--;
//            arr[left] = arr[right];
//            while (left < right && arr[left] < key)
//                left++;
//            arr[right] = arr[left];
//        }
//        arr[left] = key;
//        return left;
//    }
//    static int Quick1(vector<int>& arr, int left, int right)
//    {
//        // 优化：找一个中间值，防止单支树的情况
//        int key = arr[left];
//        int pos = left;
//        for (int i = left + 1; i <= right; i++)
//        {
//            if (key > arr[i])
//            {
//                pos++;
//                if (pos != i)
//                    swap(arr[i], arr[pos]);
//            }
//        }
//        swap(arr[left], arr[pos]);
//        return pos;
//    }
//    static void QuickSort(vector<int>& arr, int left, int right)
//    {
//        // 优化：数据量较小时使用直接插入排序
//        if (left >= right)
//            return;
//        int pos = Quick1(arr, left, right - 1);
//        QuickSort(arr, left, pos);
//        QuickSort(arr, pos + 1, right);
//    }
//};
//int main()
//{
//    vector<int> arr = { 4,5,1,6,2,7,3,8 };
//    Sort::QuickSort(arr, 0, arr.size());
//    return 0;
//}
//
#include <iostream>
#pragma warning(disable:4996)
using namespace std;
class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
			str = "";
		_capacity = _size = strlen(str);
		_str = new char[_size + 1];
		strcpy(_str, str);
		printf("拷贝：%p\n", _str);
	}
	String(const String& s)
		: _str(new char[s._size + 1])
		, _size(s._size)
		, _capacity(s._capacity)
	{
		strcpy(_str, s._str);
		printf("拷贝构造：%p\n", _str);
	}
	// 移动构造
	String(String&& s)
	{
		printf("移动构造：s：%p，str：%p\n", s._str, _str);
		swap(_str, s._str);
		_size = s._size;
		_capacity = s._capacity;
	}
	~String()
	{
		if (_str)
		{
			printf("析构：%p\n", _str);
			delete[] _str;
			_size = _capacity = 0;
			_str = nullptr;
		}
	}
	// 现代法
	String& operator=(String s)
	{
		printf("赋值重载：s：%p，str：%p\n", s._str, _str);
		swap(_str, s._str);
		_size = s._size;
		_capacity = s._capacity;
		return *this;
	}
	// 移动赋值
	String& operator=(String&& s)
	{
		printf("移动赋值：s：%p，str：%p\n", s._str, _str);
		swap(_str, s._str);
		_size = s._size;
		_capacity = s._capacity;
		return *this;
	}

private:
	char* _str;
	size_t _size;
	size_t _capacity;
};


String Test(String s)
{
	return s;
}
String Test2()
{
	String s("oo");
	return s;
}
//int main()
//{
//	String s1;
//	String s2("qwer");
//	s1 = s2;					// 赋值重载
//	
//	String s3 = String("op");	// 构造一个匿名对象并执行赋值重载 
//	String s4 = Test2();		// 
//}
#include <iostream>
#include <vector>

using namespace std;

bool CheckNums(int num, vector<int>& board)
{
	int sum = 0, tmp = num;
	while (tmp)
	{
		int digit = tmp % 10;
		tmp /= 10;
		sum += board[digit];
	}
	return num == sum;
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		if (m < 100 || n < 100 || m > 999 || n > 999)
			continue;
		vector<int> board(10, 0);
		bool flag = false;
		for (int i = 1; i <= 9; ++i)
		{
			board[i] = i * i * i;
		}
		for (int i = m; i <= n; ++i)
		{
			int sum = 0, tmp = i;
			while (tmp)
			{
				int digit = tmp % 10;
				tmp /= 10;
				sum += board[digit];
			}
			if (i == sum)
			{
				flag = true;
				cout << i << " ";
			}
		}
		if (flag)
			cout << endl;
	}
	return 0;
}