#include <iostream>
#include <vector>
using namespace std;

int N, x, pre = -1, cnt = 0;
vector <int> v;

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
		if (pre >= x)
			cnt++;
		pre = x;
	}

	if (v[0] <= v[v.size() - 1])
		cnt++;
	cout << cnt;

	return 0;
}