#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector <int> ary; // 원래 수열
vector <int> LIS; // lower_bound해서 업데이트 하는 수열
vector <int> list; // i번째 값이 lower_bound해서 받는 인덱스

int main(void)
{
	stack <int> s;
	int N, n;
	cin >> N;
	list = vector<int>(N);

	for (int i = 0; i < N; i++)
	{
		cin >> n;
		ary.push_back(n);
	}

	for (int i = 0; i < N; i++)
	{
		int index = lower_bound(LIS.begin(), LIS.end(), ary[i]) - LIS.begin();
		if (index != LIS.size())
			LIS[index] = ary[i];
		else
			LIS.push_back(ary[i]);
		list[i] = index;
	}

	int sz = LIS.size() - 1;
	for (int i = N - 1; sz != -1; i--)
	{
		if (list[i] == sz)
		{
			s.push(ary[i]);
			sz--;
		}
	}

	cout << LIS.size() << '\n';
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}

	return 0;
}