#include"main.h"
//thisָ����������ڱȺ���Ҫ��
class Data
{
public:
	bool operator==(const Data& d)	//���������
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

Data operator-(const Data& d, int days)  //ȫ����������أ�ȫ�ֵ�û��thisָ�룬���Ա����const Data& d,����Data* const this
{
	Data temp(d);

}
//operator��������
void Test()
{

}
int main()
{
	Test();
	return 0;
}