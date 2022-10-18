#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	deque <pair<int, int>> dq;
	int N, L, num;
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (i == 0)
		{
			dq.push_back({ num, i });
		}
		else
		{
			if (dq.back().first <= num)
			{
				dq.push_back({ num, i });
			}
			else
			{
				while (dq.size() != 0 && dq.back().first > num)
					dq.pop_back();
				dq.push_back({ num, i });
			}
		}
		if (i - L == dq.front().second)
			dq.pop_front();
		cout << dq.front().first << ' ';
	}
	return 0;
}