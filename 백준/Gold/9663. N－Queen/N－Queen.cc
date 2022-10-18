#include <iostream>
#include <vector>
using namespace std;
vector <bool> row; // 가로
vector <vector<bool>> dia; // 대각선
int N, cnt = 1, total = 0;

bool check(int r, int c)
{
	for (int i = 1; i < N; i++)
	{
		if ((r + i <= N && c + i <= N) && dia[r+i][c+i])
			return false;
		if ((r + i <= N && c - i > 0) && dia[r + i][c - i])
			return false;
		if ((r - i > 0 && c + i <= N) && dia[r - i][c + i])
			return false;
		if ((r - i > 0 && c - i > 0) && dia[r - i][c - i])
			return false;
	}
	return true;
}

void DFS()
{
	if (cnt == N + 1)
	{
		total++;
		return;
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			if (!row[i] && check(i, cnt))
			{
				row[i] = true;
				dia[i][cnt] = true;
				cnt++;
				DFS();
				cnt--;
				row[i] = false;
				dia[i][cnt] = false;
			}
		}
	}
}

int main(void)
{
	cin >> N;
	row = vector<bool>(N + 1, false);
	dia = vector<vector<bool>>(N + 1, vector<bool>(N+1, false));
	DFS();
	cout << total;
	return 0;
}