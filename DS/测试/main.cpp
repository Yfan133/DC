#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;

//#include <stdio.h>
//#include <string.h>
//#pragma warning(disable : 4996)
//
//int main()
//{
//	int a;
//	float b, c, d;
//	scanf("%2d%3f%4f", &a, &b, &c);
//	scanf("%f", &d);
//	printf("%d, %f, %f", a, b, c);
//	printf("\n%f", d);
//	return 0;
//}

int main()
{
    int T;
    cin >> T;
    vector<int> vec;
    int x = 0;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vec.resize(x + 2 * n);
        for (int i = x; i < x + 2 * n; i++)
        {
            cin >> vec[i];
        }
        while (k--)
        {
            vector<int> tmp(vec);
            int pos = x;
            for (int i = x; i < x + n; i++)
            {
                vec[pos++] = tmp[i];
                vec[pos++] = tmp[i + n];
            }
        }
        x += 2 * n;
    }
    for (int i = 0; i < vec.size() - 1; i++)
        cout << vec[i] << " ";
    cout << vec[vec.size() - 1];
    return 0;
}