#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <memory.h>
using namespace std;

int n;
int mat[101][101];
bool visited[101][101];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int dan = 0;
vector <int> v;

void BAEK_2667_bfs(void)
{
	queue <pair <int, int> > q;
	int cnt, dangi = 0;
	for (int i = 0; i < n; i++)
	{
		for (int s = 0; s < n; s++)
		{
			if (mat[i][s] == 1)
			{
				cnt = 1;
				q.push({ i, s });
				visited[i][s] = true;
				mat[i][s] += 1;
				dan++;
				while (!q.empty())
				{
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int j = 0; j < 4; j++)
					{
						int yy = y + dy[j];
						int xx = x + dx[j];
						if (yy < 0 || xx < 0 || xx >= n || yy >= n)
							continue;
						if (mat[yy][xx] == 1 && visited[yy][xx] == false)
						{
							cnt++;
							mat[yy][xx] += 1;
							visited[yy][xx] = true;
							q.push({ yy, xx });
						}
					}
				}
				v.push_back(cnt);
			}
		}
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int s = 0; s < n; s++)
			visited[i][s] = false;
	for (int i = 0; i < n; i++)
	{
		string a; cin >> a;
		for (int s = 0; s < n; s++)
		{
			if (a[s] == '0')
				mat[i][s] = 0;
			else
				mat[i][s] = 1;
		}
	}
	BAEK_2667_bfs();
	sort(v.begin(), v.end());
	printf("%d\n", dan);
	for (int i = 0; i < v.size(); i++)
		printf("%d\n", v[i]);
    return 0;
}