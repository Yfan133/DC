#include"main.h"
//thisָ����������ڱȺ���Ҫ��
class A
{
public:
	A(int data)				//���캯��
	{
		_data = data;
	}
	ostream& operator<<(ostream& _cout)const	//����������<<��������cout���Ҳ����������ص�thisΪ�������
	{
		cout << _data;
		return _cout;
	}
	int _data;
};
ostream& operator<<(ostream& _cout,const A& tmp)
{
	cout << tmp._data;
	return _cout;
}
int main()
{
	A a1(1);
	cout << a1 << 1 << endl << a1;
	a1 << cout;
	return 0;
}
