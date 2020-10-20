#include"main.h"
//this指针的生命周期比函数要长
class Date
{
public:
	Date(int year = 1999, int month = 11, int day = 2)	//构造
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int,int,int):" << this << endl;
	}
	Date(const Date& temp)								//拷贝构造
		:_year(temp._year)
		, _month(temp._month)
		, _day(temp._day)
	{
		cout << "Date(const Date&):" << this << endl;
	}
	~Date()												//析构,先析构最后创建的对象
	{
		cout << "~Date():" << this << endl;
	}
	Date& operator=(const Date& temp)					//函数运算符重载
	{
		if (this != &temp)
		{
			_year = temp._year;
			_month = temp._month;
			_day = temp._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};

//Date operator-(const Date& d, int days)  //全局运算符重载，全局的没有this指针，所以必须给const Data& d,类似Data* const this
//{
//	Date temp(d);
//
//}
//operator不能重载
void Test()
{
	Date d1(2020, 10, 19);
	Date d2(2020, 10, 20);
	Date d3(d2);
	d2 = d1;
	//d1 = d2 = d3;			不能这样写,可以用下面方式
	d1.operator=(d2.operator=(d3));
}
Date TestDate3(Date d)
{
	return d;
}
void TestDate()
{
	Date d1(2020, 10, 14);
	Date d2(2020, 10, 15);
	d1 = TestDate3(TestDate3(d2));
}
int main()
{
	TestDate();
	return 0;
}
//class String
//{
//public:
//	String(int capicity)
//	{
//		_arr = (int*)malloc(sizeof(int) * capicity);
//	}
//	~String()
//	{
//		if (_arr)
//		{
//			free(_arr);
//			_arr = nullptr;
//		}
//	}
//private:
//	int* _arr;
//};
//void Test()
//{
//	String d1(10);
//	String d2 = d1;	//编译器调用拷贝构造函数，构造d2
//}
//int main()
//{
//	Test();
//	return 0;
//}