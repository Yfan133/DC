#include"main.h"
//this指针的生命周期比函数要长
class Data
{
public:
	bool operator==(const Data& d)	//运算符重载
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}
	Data& operator+=(const Data& d)
	{

	}
	Data operator+(/*Data* const this,*/int days)
	{
		Data temp(*this);
		temp._day += days;
		return temp;
	}
private:
	int _year;
	int _month;
	int _day;
};

Data operator-(const Data& d, int days)  //全局运算符重载，全局的没有this指针，所以必须给const Data& d,类似Data* const this
{
	Data temp(d);

}
//operator不能重载
void Test()
{

}
int main()
{
	Test();
	return 0;
}