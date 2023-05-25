#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

deque <pair<int, int>> dq;
vector <int> v;
priority_queue <int, vector<int>, greater<int>> pq;
int N, K, num, mn = 100000000;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		pq.push(num);
	}

	int f = pq.top();
	v.push_back(f);
	pq.pop();

	for (int i = 1; i < N; i++)
	{
		num = pq.top();
		v.push_back(num);
		pq.pop();

		if (dq.empty())
		{
			dq.push_back({ num - f, i - 1 });
		}
		else
		{
			if (dq.back().first <= num - f)
			{
				dq.push_back({ num - f, i - 1});
			}
			else
			{
				while (dq.size() != 0 && dq.back().first > num - f)
					dq.pop_back();
				dq.push_back({ num - f, i - 1});
			}
		}
		if (i >= N - K - 1)
			mn = min(mn, dq.front().first + (v[i] - v[i - (N - K - 1)]));
		if (i - (N - K) == dq.front().second)
			dq.pop_front();
		f = num;
	}

	cout << mn;

	return 0;
}