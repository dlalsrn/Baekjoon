#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
	string name;
	int len;
	int freeze;
	int start;
	int fail;
}NODE;

bool cmp(NODE a, NODE b)
{
	if (a.len != b.len)
		return a.len > b.len;
	else
	{
		if (a.freeze != b.freeze)
			return a.freeze < b.freeze;
		else
		{
			if (a.start != b.start)
				return a.start < b.start;
			else
			{
				if (a.fail != b.fail)
					return a.fail < b.fail;
				else
					return a.name < b.name;
			}
		}
	}
}

int N, W, X, F, f, L, S, mx_L, mx_F, mx_S, cnt = 0;
string n, streak, x;
vector <NODE> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> W;

	for (int t = 0; t < N; t++)
	{
		cin >> n;
		streak = "";
		for (int i = 0; i < 7; i++)
		{
			cin >> x;
			streak += x;
		}

		mx_L = 0, mx_F = 0, mx_S = 0, L = 0, X = 0, F = 0, S = 0, cnt = 0, f = 0;
		for (int w = 0; w < W; w++)
		{
			for (int i = 0; i < 7; i++)
			{
				if (streak[W * i + w] == 'O')
				{
					if (L == 0)
					{
						L++;
						S = cnt;
					}
					else
					{
						L++;
						F += f;
						f = 0;
					}
				}
				else if (streak[W * i + w] == 'F')
				{
					if (L != 0)
						f++;
				}
				else if (streak[W * i + w] == 'X')
				{
					if (L > mx_L)
					{
						mx_L = L;
						mx_S = S;
						mx_F = F;
					}
					else if (L == mx_L)
					{
						if (mx_F > F)
						{
							mx_F = F;
							mx_S = S;
						}
					}
					L = 0, F = 0, S = 0, f = 0;
					X++;
				}
				cnt++;
			}
		}
		if (L > mx_L)
		{
			mx_L = L;
			mx_S = S;
			mx_F = F;
		}
		else if (L == mx_L)
		{
			if (mx_F > F)
			{
				mx_F = F;
				mx_S = S;
			}
		}
		NODE temp;
		temp.name = n, temp.freeze = mx_F, temp.len = mx_L;
		temp.fail = X, temp.start = mx_S;
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), cmp);

	//for (int i = 0; i < N; i++)
		//cout << v[i].name << ' ' << v[i].len << ' ' << v[i].freeze << ' ' << v[i].start << ' ' << v[i].fail << '\n';
	//cout << "==================================\n";
	cnt = 1;
	for (int i = 0; i < N; i++)
	{
		if (i != 0 && (v[i].len != v[i - 1].len || v[i].freeze != v[i - 1].freeze || v[i].start != v[i - 1].start || v[i].fail != v[i - 1].fail))
			cnt++;
		cout << cnt << ". " << v[i].name << '\n';
	}
}