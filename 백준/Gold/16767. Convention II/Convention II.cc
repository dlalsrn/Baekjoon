#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
	priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> wait;
	int N, arrive, eat, time, max = 0, cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arrive >> eat;
		q.push(make_pair(arrive, make_pair(eat, i)));
	}
	time = q.top().first + q.top().second.first;
	q.pop();
	cnt++;
	while (cnt != N)
	{
		while (!q.empty() && time >= q.top().first)
		{
			wait.push(make_pair(q.top().second.second, make_pair(q.top().first, q.top().second.first)));
			q.pop();
		}
		if (!wait.empty())
		{
			if (max < time - wait.top().second.first)
				max = time - wait.top().second.first;
			time += wait.top().second.second;
			wait.pop();
			cnt++;
		}
		else if (!q.empty())
		{
			time = q.top().first + q.top().second.first;
			q.pop();
			cnt++;
		}
	}
	cout << max;
	return 0;
}