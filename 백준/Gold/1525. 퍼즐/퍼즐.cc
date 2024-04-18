#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ans = -1;
char c;
string x = "", t;
map <string, int> m;
queue <string> q;

void BFS()
{
	while (!q.empty())
	{
		x = q.front();
		q.pop();

		if (x == "123456780")
		{
			ans = m[x];
			break;
		}

		int zero = x.find('0');
		for (int i = 0; i < 4; i++)
		{
			t = x;
			int yy = (zero / 3) + dy[i];
			int xx = (zero % 3) + dx[i];

			if (yy < 0 || yy >= 3 || xx < 0 || xx >= 3) continue;

			c = t[zero];
			t[zero] = t[yy * 3 + xx];
			t[yy * 3 + xx] = c;

			if (!m[t])
			{
				m[t] = m[x] + 1;
				q.push(t);
			}
		}
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	for (int i = 0; i < 9; i++)
	{
		cin >> c;
		x += c;
	}

	q.push(x);
	BFS();

	cout << (ans == -1 ? -1 : ans);

	return 0;
}