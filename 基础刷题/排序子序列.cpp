#include <iostream> 
#include <vector> 
using namespace std;
int main()
{
	int n; cin >> n;
	vector<int> ar;
	ar.resize(n);
	for (int& i : ar)
		cin >> i;
	int res = 0;
	int i = 0;
	while (i < n)
	{
		if (ar[i] < ar[i + 1])
		{
			while (i < n - 1 && ar[i] <= ar[i + 1]) //����һ����<=�������������Ҳ���� 
				i++;
			res++;
			i++; //�������Ϊʲô����Խ�磬�ڲ�����һ��������֮��i++����ָ����������һ��Ԫ�ء� 
		}
		else if (ar[i] > ar[i + 1])
		{
			while (i < n - 1 && ar[i] >= ar[i + 1])
				i++;
			res++;
			i++;
		}
		else
			i++; //�����һ�������Ǻ���һ�������
	}
	cout << res << endl;
	return 0;
}
