#include"main.h"
//this指针的生命周期比函数要长

class Date
{
public:
	Date(int year, int month,int day,int time)
		:_year(year)
		,_month(month)
		,_day(day)
		,_time(time)
	{
		/*_year = year;
		_month = month;
		_day = day;
		_time = time;*/
	}

private:
	int _year;
	int _month;
	const int _day;
	int& _time;
};
int main()
{
	Date A(2020, 10, 30, 10);
	return 0;
}
