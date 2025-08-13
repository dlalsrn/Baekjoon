#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> solution(vector<string> park, vector<string> routes)
{
	vector<int> answer;
	int h = park.size();
	int w = park[0].size();
	int x, y;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (park[i][j] == 'S')
			{
				y = i;
				x = j;
			}
		}
	}

	for (int i = 0; i < routes.size(); i++)
	{
		char dir = routes[i][0];
		int cnt = routes[i][2] - '0';

		if (dir == 'E' || dir == 'W')
		{
			bool isValid = true;
			int forward = dir == 'E' ? 1 : -1;

			if (0 <= x + cnt * forward && x + cnt * forward < w)
			{
				for (int j = 1; j <= cnt; j++)
				{
					if (park[y][x + (j * forward)] == 'X')
					{
						isValid = false;
						break;
					}
				}

				if (isValid) x += cnt * forward;
			}
		}
		else
		{
			bool isValid = true;
			int forward = dir == 'S' ? 1 : -1;

			if (0 <= y + cnt * forward && y + cnt * forward < h)
			{
				for (int j = 1; j <= cnt; j++)
				{
					if (park[y + (j * forward)][x] == 'X')
					{
						isValid = false;
						break;
					}
				}

				if (isValid) y += cnt * forward;
			}
		}
	}

	answer.push_back(y);
	answer.push_back(x);

	return answer;
}