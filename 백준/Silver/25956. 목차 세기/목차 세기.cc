#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef struct
{
	int level;
	int index;
	int sub;
}NODE;
stack <NODE> s;
vector <int> ans;
int N, level, cnt, last;

int main(void)
{
	cin >> N;

	ans = vector<int>(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> level;
		if (i == 0 && level != 1)
		{
			cout << -1;
			return 0;
		}
		else
		{
			if (s.empty())
				s.push({ level, i, 0 });
			else
			{
				if (s.top().level <= level)
				{
					if (level - s.top().level >= 2)
					{
						cout << -1;
						return 0;
					}
					s.push({ level, i, 0 });
				}
				else
				{
					cnt = 0;
					last = s.top().level;
					while (!s.empty() && s.top().level >= level)
					{
						if (last - s.top().level >= 2)
						{
							cout << -1;
							return 0;
						}
						if (last != s.top().level)
						{
							s.top().sub += cnt;
							cnt = 0;
							if (s.top().level == level)
								break;
						}
						ans[s.top().index] = s.top().sub;
						last = s.top().level;
						s.pop();
						cnt++;
					}
					s.push({ level, i, 0 });
				}
			}
		}
	}

	last = s.top().level;
	while (!s.empty())
	{
		if (last - s.top().level >= 2)
		{
			cout << -1;
			return 0;
		}
		if (last != s.top().level)
		{
			s.top().sub += cnt;
			cnt = 0;
		}
		ans[s.top().index] = s.top().sub;
		last = s.top().level;
		s.pop();
		cnt++;
	}

	for (int i = 0; i < N; i++)
		cout << ans[i] << '\n';

	return 0;
}