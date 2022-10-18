#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	stack <pair<int, int>> s;
	vector <pair<int, int>> v;
	int N, num;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		pair<int, int> temp = { i, num };
		if (s.empty())
		{
			s.push(temp);
		}
		else
		{
			if (s.top().second >= num)
				s.push(temp);
			else
			{
				while (!s.empty() && s.top().second < num)
				{
					pair<int, int> t = s.top();
					s.pop();
					v.push_back({ t.first, num });
				}
				s.push(temp);
			}
		}
	}
	while (!s.empty())
	{
		v.push_back({ s.top().first, -1 });
		s.pop();
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i].second << ' ';

	return 0;
}