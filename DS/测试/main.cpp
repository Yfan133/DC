#include<iostream>
#include<string>
using namespace std;
#pragma warning(disable:4996)
//class A
//{
//public:
//	A(const char* ptr = "")
//	{
//		_str = new char[strlen(ptr) + 1];
//		strcpy(_str, ptr);
//	}
//	void resize(size_t n)
//	{
//		char* tmp = new char[n];
//		strcpy(tmp, _str);
//		delete[] _str;
//		_str = tmp;
//	}
//	~A()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};
//int main()
//{
//	char* a = new char[5];
//	a[0] = 'q';
//	a[1] = 'w';
//	a[2] = 'e';
//	a[3] = 'r';
//	a[4] = '\0';
//	char* b = (char*)"asdf";
//	char* c=new char[9];
//	strcpy(c, a);
//	strcat(c + 4, b);
//	delete[] a;
//
//	return 0;
//}
#include<vector>
int singleNumber(vector<int>& nums)
{
    int bitSum[32] = { 0 };
     //统计每一位1的个数
     for(int i = 0; i < nums.size(); i ++)
     {
         int bitMask = 1; //向左移位  & 
         for(int j = 31; j >= 0; j --)
         {
             if(nums[i] & bitMask)//bit == 1
                 bitSum[j] += 1;//%3
             bitMask = bitMask << 1;//1——》  10   100 1000
         }
     }

     int res = 0;

     for(int i = 0; i < 32; i ++)
     {
         res = res << 1;
         res += bitSum[i] % 3;
     }

     return res;
}
class A
{
public:
    A(int a)
    {

    }

};
int main()
{
    A* p = new A(1);
    return 0;
}
//void Test(void* t)
//{
//	cout << "void*" << endl;
//}
//void Test(int t)
//{
//	cout << "int" << endl;
//}
//int main()
//{
//	int* p = NULL;
//	int* pt = nullptr;
//	Test(NULL);
//	Test(nullptr);
//	return 0;
//}