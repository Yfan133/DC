#include"main.h"
//thisָ����������ڱȺ���Ҫ��
class Date
{
public:
	Date(int year = 1999, int month = 11, int day = 2)	//����
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int,int,int):" << this << endl;
	}
	Date(const Date& temp)								//��������
		:_year(temp._year)
		, _month(temp._month)
		, _day(temp._day)
	{
		cout << "Date(const Date&):" << this << endl;
	}
	~Date()												//����,��������󴴽��Ķ���
	{
		cout << "~Date():" << this << endl;
	}
	Date& operator=(const Date& temp)					//�������������
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

//Date operator-(const Date& d, int days)  //ȫ����������أ�ȫ�ֵ�û��thisָ�룬���Ա����const Data& d,����Data* const this
//{
//	Date temp(d);
//
//}
//operator��������
void Test()
{
	Date d1(2020, 10, 19);
	Date d2(2020, 10, 20);
	Date d3(d2);
	d2 = d1;
	//d1 = d2 = d3;			��������д,���������淽ʽ
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
//	String d2 = d1;	//���������ÿ������캯��������d2
//}
//int main()
//{
//	Test();
//	return 0;
//}