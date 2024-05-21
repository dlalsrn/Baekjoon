#include <bits/stdc++.h>
using namespace std;

int N, mx_len = 1, mx_cnt = 1, cnt = 1, diff;
bool check, cont = false;
map <string, int> m;
vector <string> v;
vector <string> pre, t, ans;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	v.resize(N + 1);

	for (int i = 1; i <= N; i++) cin >> v[i];

	for (int i = 1; i <= N; i++)
	{
		if (!m[v[i]]) m[v[i]] = i;
		else
		{
			diff = i - m[v[i]];
			check = true;
			int jump = 0;
			for (int j = 0; j < diff; j++)
			{
				if (i + j > N)
				{
					check = false;
					break;
				}
				if ((i + j) - m[v[i + j]] != diff)
				{
					check = false;
					pre = vector <string>();
					break;
				}
				jump++;
				m[v[i + j]] = i + j;
			}

			if (check)
			{
				t = vector<string>();
				for (int j = 0; j < diff; j++) t.push_back(v[i + j]);

				if (pre.size() != 0 && pre == t)
				{
					cnt++;
					if (mx_cnt < cnt)
					{
						ans = t;
						mx_cnt = cnt;
						mx_len = ans.size();
					}
				}
				else
				{
					if (mx_cnt == 1)
					{
						ans = t;
						mx_cnt = 2;
						mx_len = ans.size();
					}
					else if (mx_cnt < cnt)
					{
						ans = t;
						mx_cnt = cnt;
						mx_len = ans.size();
					}
					cnt = 2;
				}

				pre = t;
			}
			i += jump - 1;
		}
	}

	if (mx_cnt < cnt)
	{
		ans = t;
		mx_cnt = cnt;
		mx_len = ans.size();
	}

	if (mx_cnt == 1)
	{
		cout << -1;
		return 0;
	}

	cout << mx_len << ' ' << mx_cnt << '\n';

	for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';

	return 0;
}
