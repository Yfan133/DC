#include"main.h"
class String
{
public:
	String(int capicity = 10)
	{
		_pData = (int*)malloc(sizeof(int) * capicity);
	}
	~String()
	{
		if (_pData)
		{
			free(_pData);
			_pData = nullptr;
		}
	}
private:
	int* _pData;
};
class 
{
private:
	String _person;
	int _age;
};
void Test()
{
	String d1;
}
int main()
{
	Test();
	return 0;
}