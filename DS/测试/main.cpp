#include<iostream>
#include<string>
#include<vector>
#include<queue>
//#include<stack>
using namespace std;
#pragma warning(disable:4996)
//int Quick(vector<int>& arr, int left, int right)
//{
//	
//}
//void QuickSort(vector<int>& arr,int left,int right)
//{
//	
//}
//int main()
//{
//	vector<int> arr = { 49,38,56,75,12,99,68,75,49 };
//	QuickSort(arr, 0, arr.size());
//	return 0;
//}
void fun(int a[], char b[]) //这里是char*和int*
{
    a[0] = 2;
    b[0] = 'w';
    printf("%d %s", a[0], b);
}
class A
{
    unsigned a : 29;
    //unsigned b : 11;
    //unsigned c : 4;
    //unsigned d : 29;
    char index;
};
int main()
{
    string ar("qwerasdf");
    string br;
    
    br +=ar.substr(4);
    ar.erase(2, 3);

    return 0;
}
