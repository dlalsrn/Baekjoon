#include <iostream>
#include <vector>
using namespace std;
vector <vector<int>> map;
vector <vector<bool>> row; // 가로
vector <vector<bool>> col; // 열
vector <vector<bool>> check;
vector <vector<vector<bool>>> sq; // 3x3 보드
int zero_cnt = 0, cnt = 0;
bool TF = false;

void solve()
{
	if (cnt == zero_cnt)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << map[i][j];
			cout << '\n';
		}
		TF = true;
		return;
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (check[i][j])
					continue;
				for (int k = 1; k <= 9; k++)
				{
					if (row[i][k] || col[j][k] || sq[i / 3][j / 3][k])
						continue;
					row[i][k] = true;
					col[j][k] = true;
					sq[i / 3][j / 3][k] = true;
					check[i][j] = true;
					map[i][j] = k;
					cnt++;
					solve();
					if (TF)
						return;
					row[i][k] = false;
					col[j][k] = false;
					sq[i / 3][j / 3][k] = false;
					check[i][j] = false;
					map[i][j] = 0;
					cnt--;
				}
				return;
			}
		}
	}
}

int main(void)
{
	string line;
	int n;
	map = vector<vector<int>>(9, vector<int>(9));
	row = vector<vector<bool>>(9, vector<bool>(10, false));
	col = vector<vector<bool>>(9, vector<bool>(10, false));
	check = vector<vector<bool>>(9, vector<bool>(9, false));
	sq = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(10, false)));
	for (int i = 0; i < 9; i++)
	{
		cin >> line;
		for (int j = 0; j < 9; j++)
		{
			n = line[j] - '0';
			map[i][j] = n;
			if (n != 0)
			{
				row[i][n] = true;
				col[j][n] = true;
				sq[i / 3][j / 3][n] = true;
				check[i][j] = true;
			}
			else
				zero_cnt++;
		}
	}

	solve();

	return 0;
}