#include <iostream>
using namespace std;

int WayToTar(int row, int col)
{
    if (row == 0 || col == 0)
        return 1;
    return WayToTar(row - 1, col) + WayToTar(row, col - 1);
}

int main()
{
    int row, col;
    while (cin >> row >> col)
    {
        cout << WayToTar(row, col) << endl;
    }
    return 0;
}