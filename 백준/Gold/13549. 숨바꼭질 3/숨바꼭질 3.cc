#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	queue <pair<int, int>> q;
	bool TF[100001] = { 0 };
	int loc[100001] = { 0 };
	int N, K;
	cin >> N >> K;
	q.push({ N, 0 });
	loc[N] = 0;
	TF[N] = true;
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		int L = temp.first;
		int cnt = temp.second;
		if (L - 1 >= 0)
		{
			if (TF[L - 1] == false)
			{
				TF[L - 1] = true;
				loc[L - 1] = cnt+1;
				q.push({ L - 1, cnt +1});
			}
			else
			{
				if (loc[L - 1] > cnt+1)
				{
					loc[L - 1] = cnt+1;
					q.push({ L - 1, cnt+1});
				}
			}
		}
		if (L + 1 <= 100000)
		{
			if (TF[L + 1] == false)
			{
				TF[L + 1] = true;
				loc[L + 1] = cnt+1;
				q.push({ L + 1, cnt+1});
			}
			else
			{
				if (loc[L + 1] > cnt+1)
				{
					loc[L + 1] = cnt+1;
					q.push({ L + 1, cnt+1});
				}
			}
		}
		if (L * 2 <= 100000)
		{
			if (TF[L * 2] == false)
			{
				TF[L * 2] = true;
				loc[L * 2] = cnt;
				q.push({ L * 2, cnt});
			}
			else
			{
				if (loc[L * 2] > cnt)
				{
					loc[L * 2] = cnt;
					q.push({ L * 2, cnt});
				}
			}
		}
	}

	cout << loc[K];
	return 0;
}