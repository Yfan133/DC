#include<iostream>
using namespace std;
#pragma warning (disable:4996)
int main()
{
    char data;
    while (scanf("%c", &data) != EOF)
    {
        //getchar();
        if (data == 'A' || data == 'a' || data == 'E' || data == 'e' || data == 'I' || data == 'i' || data == 'O' || data == 'o' || data == 'U' || data == 'u')
            cout << "Vowel" << endl;
        else
            cout << "Consonant" << endl;
    }
    return 0;
}