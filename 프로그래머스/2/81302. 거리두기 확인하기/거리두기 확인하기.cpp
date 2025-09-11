#include <string>
#include <vector>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool DFS(vector<string>& room, vector<vector<bool>>& visit, int y, int x, int cnt)
{
	if (room[y][x] == 'P' && cnt != 0)
	{
		return true;
	}
	else if (cnt == 2)
	{
		return false;
	}

	bool isPerson = false;

	for (int k = 0; k < 4; k++)
	{
		int yy = y + dy[k];
		int xx = x + dx[k];

		if (yy < 0 || xx < 0 || yy >= room.size() || xx >= room[0].size() || visit[yy][xx] || room[yy][xx] == 'X')
		{
			continue;
		}

		visit[yy][xx] = true;
		isPerson |= DFS(room, visit, yy, xx, cnt + 1);
	}

	return isPerson;
}

vector<int> solution(vector<vector<string>> places)
{
	vector<int> answer;

	for (int i = 0; i < places.size(); i++)
	{
		vector<string> room;
		vector<vector<bool>> visit(5, vector<bool>(5, false));
		bool isPerson = false;

		for (string s : places[i])
		{
			room.push_back(s);
		}

		for (int r = 0; r < room.size(); r++)
		{
			for (int c = 0; c < room[r].size(); c++)
			{
				if (room[r][c] == 'P')
				{
					visit[r][c] = true;
					isPerson |= DFS(room, visit, r, c, 0);
				}
			}
		}
		
		answer.push_back(isPerson ? 0 : 1);
	}

	return answer;
}