#include <bits/stdc++.h>
using namespace std;

int N, M, K, x, y, z, ans = 0;
int dx[8] = { 1, 1, -1, -1, 1, 0, -1, 0 };
int dy[8] = { 1, -1, 1, -1, 0, 1, 0, -1 };
vector <vector<int>> value, m;
vector <vector<vector<int>>> node;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> N >> M >> K;

	value = vector<vector<int>>(N, vector<int>(N));
	m = vector<vector<int>>(N, vector<int>(N, 5));
	node = vector<vector<vector<int>>>(N, vector<vector<int>>(N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> value[i][j];

	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> z;
		node[x - 1][y - 1].push_back(z);
	}

	for (int k = 0; k < K; k++)
	{
		for (int i = 0; i < N; i++) // 봄, 여름
		{
			for (int j = 0; j < N; j++)
			{
				sort(node[i][j].begin(), node[i][j].end());

				for (int r = 0; r < node[i][j].size(); r++)
				{
					if (m[i][j] >= node[i][j][r]) // 남는 양분이 더 많으면
					{
						m[i][j] -= node[i][j][r];
						node[i][j][r]++;
					}
					else // 양분이 없으면 죽음
					{
						for (int t = node[i][j].size() - 1; t >= r; t--)
						{
							m[i][j] += node[i][j][t] / 2;
							node[i][j].pop_back();
						}
						break;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) // 가을
		{
			for (int j = 0; j < N; j++)
			{
				for (int r = 0; r < node[i][j].size(); r++)
				{
					if (node[i][j][r] % 5 == 0)
					{
						for (int k = 0; k < 8; k++)
						{
							int yy = i + dy[k];
							int xx = j + dx[k];
							
							if (yy < 0 || yy >= N || xx < 0 || xx >= N) continue;

							node[yy][xx].push_back(1);
						}
					}
				}
			}
		}

		for (int i = 0; i < N; i++) // 겨울
			for (int j = 0; j < N; j++)
				m[i][j] += value[i][j];
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ans += node[i][j].size();

	cout << ans;

	return 0;
}