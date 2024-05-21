#include <bits/stdc++.h>
using namespace std;
using tp = tuple<int, int, string>;

int N, W, D, P, ans = 0, cnt = 0;
string S;
map <string, int> money;
vector <tp> v;
vector <bool> check(70, false);

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> S >> W >> D >> P;
		v.push_back({ 7 * (W - 1) + D, P, S });
	}

	for (int i = 0; i < N; i++)
	{
		cin >> S >> P;
		money[S] = P;
	}

	for (int i = 0; i < N; i++)
	{
		auto [D, P, S] = v[i];
		if (money[S] >= P) check[D] = true;
	}

	cnt = 0;
	for (int i = 0; i < 70; i++)
	{
		if (check[i]) cnt++;
		else
		{
			ans = max(ans, cnt);
			cnt = 0;
		}
	}

	cout << max(ans, cnt);

	return 0;
}
