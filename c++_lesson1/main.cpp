// ���ȼ����в���
//int main()
//{
//	vector<int> arr = { 1,2,3,6,8,10 };
//	Test1();
//	Test2();
//	//sort(arr.begin(), arr.end(), [](int a, int b) {return a > b; });
//	return 0;
//}

// ���ȼ�����ģ��ʵ��
//int main()
//{
//	TestMyPriorityQueue1();
//	TestMyPriorityQueue2();
//	return 0;
//}

// ����ָ��ģ��ʵ��
//int main()
//{
//	
//	// Test1();
//	// Test2();
//	// Test3();
//	// Test4();
//	// Test5();
//	// TestThread();
//	// Test6();
//	// Test7();
//	
//	return 0;
//}

// ��ɢ��ģ��ʵ��
//#include "hashTable.h"
//int main()
//{
//	TestHt();
//	return 0;
//}

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> t(n);
        vector<int> w(n);
        for (int i = 0; i < n; ++i)
            cin >> t[i];
        for (int i = 0; i < n; ++i)
            cin >> w[i];
        // ͬһʱ��ѡ�����ҫֵ
        unordered_map<int, int> board;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (board.count(t[i]) == 1)
            {
                // �ظ�
                int value = board[t[i]];
                if (value > w[i])
                    ans -= w[i];
                else
                {
                    ans = ans - 2 * value + w[i];
                    board[t[i]] = w[i];
                }
            }
            else
            {
                ans += w[i];
                board[t[i]] = w[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}











