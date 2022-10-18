#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(void)
{
	int N, x1, x2, dis;
	int sum = 0;
	stack <pair<int, int>> s;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x1 >> x2;
		q.push(make_pair(x1, x2));
	}

	while (!q.empty())
	{
		pair<int, int> t = q.top();
		q.pop();

		if (s.empty())
		{
			dis = t.second - t.first;
			sum += dis * dis;
			s.push(t);
		}
		else
		{
			if (t.first >= s.top().second)
			{
				dis = t.second - t.first;
				sum += dis * dis;
				s.push(t);
			}
			else
			{
				if (t.second > s.top().second)
				{
					dis = t.second - t.first;
					sum += dis * dis;
					dis = s.top().second - t.first;
					sum -= dis * dis;
					s.push(t);
				}
			}
		}
	}
	cout << sum << '\n';
	return 0;
}