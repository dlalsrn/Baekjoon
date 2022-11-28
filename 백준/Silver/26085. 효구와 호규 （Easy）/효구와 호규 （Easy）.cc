#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
int N, M, O = 0, Z = 0;
bool TF = false;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void)
{
	cin >> N >> M;

	if (N * M % 2)
		cout << -1;
	else
	{
		map.resize(N, vector<int>(M));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> map[i][j];
				map[i][j] ? O++ : Z++;
			}
		}

		if (O % 2 || Z % 2)
			cout << -1;
		else
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					for (int k = 0; k < 4; k++)
					{
						int xx = j + dx[k];
						int yy = i + dy[k];
						if (xx < 0 || xx > M - 1 || yy < 0 || yy > N - 1)
							continue;
						if (map[i][j] == map[yy][xx])
						{
							TF = true;
							break;
						}
					}
					if (TF)
						break;
				}
				if (TF)
					break;
			}
			cout << (TF ? 1 : -1);
		}
	}

	return 0;
}