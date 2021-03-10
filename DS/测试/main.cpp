//#include <iostream>
//#include <vector>
//using namespace std;
//class Sort
//{
//public:
//    static int Quick2(vector<int>& arr, int left, int right)
//    {
//        int key = arr[left];
//        while (left < right)
//        {
//            while (left < right && arr[right] >= key)
//                right--;
//            arr[left] = arr[right];
//            while (left < right && arr[left] < key)
//                left++;
//            arr[right] = arr[left];
//        }
//        arr[left] = key;
//        return left;
//    }
//    static int Quick1(vector<int>& arr, int left, int right)
//    {
//        // 优化：找一个中间值，防止单支树的情况
//        int key = arr[left];
//        int pos = left;
//        for (int i = left + 1; i <= right; i++)
//        {
//            if (key > arr[i])
//            {
//                pos++;
//                if (pos != i)
//                    swap(arr[i], arr[pos]);
//            }
//        }
//        swap(arr[left], arr[pos]);
//        return pos;
//    }
//    static void QuickSort(vector<int>& arr, int left, int right)
//    {
//        // 优化：数据量较小时使用直接插入排序
//        if (left >= right)
//            return;
//        int pos = Quick1(arr, left, right - 1);
//        QuickSort(arr, left, pos);
//        QuickSort(arr, pos + 1, right);
//    }
//};
//int main()
//{
//    vector<int> arr = { 4,5,1,6,2,7,3,8 };
//    Sort::QuickSort(arr, 0, arr.size());
//    return 0;
//}
//
#include <iostream>
using namespace std;

class A
{
public:
	void funa()
	{
		cout << "A" << endl;
	}
};
class B : public A
{
public:
	void funb()
	{
		cout << "B" << endl;
	}
};
int main()
{
	B b;
	A* a = &b;
	a->funa();
	a->funb();
	return 0;
}