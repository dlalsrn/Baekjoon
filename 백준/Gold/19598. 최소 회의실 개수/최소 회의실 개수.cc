// 강의실
#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> temp;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> time;
	int N, s, e, cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s >> e;
		temp.push(make_pair(s, e));
	}

	for (int i = 0; i < N; i++)
	{
		if (time.empty())
		{
			time.push(make_pair(temp.top().second, temp.top().first));
			temp.pop();
			cnt++;
		}
		else
		{
			if (temp.top().first >= time.top().first)
				time.pop();
			else
				cnt++;
			time.push(make_pair(temp.top().second, temp.top().first));
			temp.pop();
		}
	}
	cout << cnt;
	return 0;
}