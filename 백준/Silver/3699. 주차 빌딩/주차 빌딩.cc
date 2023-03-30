#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int T, h, l, c, mx;
vector<vector<int>> v;
map <int, pair<int, int>> m;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> h >> l;

		mx = 0;
		v = vector<vector<int>>(h);

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < l; j++)
			{
				cin >> c;
				if (c != -1)
				{
					mx = max(mx, c);
					m[c] = make_pair(i, j);
				}
				v[i].push_back(c);
			}
		}

		int round[50] = { 0 };
		int sum = 0;
		for (int i = 1; i <= mx; i++)
		{
			pair<int, int> point = m[i]; // y, x
			int yy = point.first, xx = (point.second + round[yy] + l) % l;
			int s = 0;
			s += yy * 20;

			if (xx <= l - xx)
			{
				s += xx * 5;
				round[yy] = (round[yy] - xx) % l;
			}
			else
			{
				s += (l - xx) * 5;
				round[yy] = (round[yy] + (l - xx)) % l;
			}
			sum += s;
		}

		cout << sum << '\n';
	}
}