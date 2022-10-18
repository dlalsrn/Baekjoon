#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <memory.h>
using namespace std;

int n, m;
int mat[101][101];
int visited[101][101];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void BAEK_2178_bfs(int sy, int sx)
{
	queue <pair <int, int> > q;
	q.push({ sy, sx });
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy < 0 || xx < 0 || xx >= m || yy >= n)
				continue;
			if (mat[yy][xx] == 1 && visited[yy][xx] == 1)
			{
				visited[yy][xx] = visited[y][x] + 1;
				q.push({ yy, xx });
			}
		}
	}
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int s = 0; s < m; s++)
			visited[i][s] = 1;

	for (int i = 0; i < n; i++)
	{
		string a; cin >> a;
		for (int s = 0; s < m; s++)
		{
			if (a[s] == '0') 
				mat[i][s] = 0;
			else 
				mat[i][s] = 1;
		}
	}
	BAEK_2178_bfs(0, 0);
	printf("%d\n", visited[n - 1][m - 1]);
    return 0;
}