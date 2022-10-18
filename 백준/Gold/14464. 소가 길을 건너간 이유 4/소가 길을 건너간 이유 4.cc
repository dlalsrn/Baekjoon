#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int C, N, a, b, cnt = 0;
	vector <pair<int, int>> chicken;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cow;
	cin >> C >> N;
	for (int i = 0; i < C; i++)
	{
		cin >> a;
		chicken.push_back(make_pair(a, 0));
	}
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		cow.push(make_pair(b, a));
	}
	sort(chicken.begin(), chicken.end());
	while (!cow.empty())
	{
		for (int i = 0; i < C; i++)
		{
			if ((chicken[i].first >= cow.top().second && chicken[i].first <= cow.top().first) && chicken[i].second != 1)
			{
				cnt++;
				chicken[i].second = 1;
				break;
			}
		}
		cow.pop();
	}
	cout << cnt;
	return 0;
}