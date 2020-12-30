#include <iostream>
#include <string>
using namespace std;
class A
{
public:
	int fd;
	A(int i  = 1)
	{
		fd = i;
	}
};
int main()
{
	A* p = new A(2);
	A* p2 = new A;
	return 0;
}