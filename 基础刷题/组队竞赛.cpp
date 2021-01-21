#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;
int main()
{
	int n;
	cin >> n;
	int size = 3 * n;
	vector<int> ar(size, 0);
	for (int i = 0; i < size; i++)
		cin >> ar[i];
	sort(ar.begin(), ar.end());
	long long res = 0;
	for (int i = n; i < size; i += 2)
		res += ar[i];
	cout << res << endl;
	return 0;
}
