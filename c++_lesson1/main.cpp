#include"main.h"
class Date
{
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year; // Äê
	int _month; // ÔÂ
	int _day; // ÈÕ
};
int main()
{
	Date d1, d2;
	d1.SetDate(2018, 5, 1);
	return 0;
}