#include"main.h"
//this指针的生命周期比函数要长
//class A
//{
//public:
//	A()
//	{
//		_count++;
//	}
//	A(const A& tmp)
//	{
//		_count++;
//	}
//	//static int GetACount()	//static修饰的成员函数
//	//{
//	//	return _count;
//	//}
////private:
//	static int _count;		//static修饰的成员变量
//};
//int A::_count = 0;
//int main()
//{
//	cout << A::_count << endl;
//	//cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::_count << endl;
//	cout << a1._count << endl;
//	//cout << A::GetACount() << endl;
//	cout << sizeof(A);
//	return 0;
//}
int* printNumbers(int n, int* returnSize)
{
    *returnSize = 1;
    int* arr = (int*)malloc(4);
    for (int i = 0; i < n; i++)
    {
        (*returnSize) *= 10;
        arr = (int*)realloc(arr, sizeof(int) * (*returnSize));
        for (int i = (*returnSize) / 10; i < *returnSize; i++)
        {
            arr[i - 1] = i;
        }
    }
    (*returnSize) -= 1;
    return arr;
}
int main()
{
    int a = 3;
    int size;
    int* p = printNumbers(a, &size);

}