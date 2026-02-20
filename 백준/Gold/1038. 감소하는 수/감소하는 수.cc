#include <bits/stdc++.h>
using namespace std;

int N;
int cnt = 0;
vector<int> v(10, 0);
string str = "";
string answer = "";
bool check = false;

void BackTrack(int n, int sz)
{
	if (check) return;
	if (sz == 0)
	{
		if (cnt == N)
		{
			answer = str;
			check = true;
		}

		++cnt;

		return;
	}

	for (int i = 0; i < n; ++i)
	{
		str.push_back('0' + i);
		BackTrack(i, sz - 1);
		str.pop_back();

		if (check) return;
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= 10; ++i)
	{
		for (int j = i - 1; j < 10; ++j)
		{
			str.push_back('0' + j);
			BackTrack(j, i - 1);
			str.pop_back();

			if (check) break;
		}
		if (check) break;
	}

	if (answer != "") cout << answer;
	else cout << -1;

	return 0;
}