#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool check(vector<vector<pair<int, int>>>& v, string id)
{
	vector<int> cnt(26, 0);
	for (int i = 0; i < id.size(); i++)
		cnt[id[i] - 'a']++;
	for (int i = 0; i < id.size(); i++)
		if (v[id[i] - 'a'].size() < cnt[id[i]-'a'])
			return false;
	return true;
}

int main(void)
{
	pair<int, int> temp;
	int N, M, C, min = 2501, min_i = 0;
	int x = 0, y = 0, cnt = 0, up = 0, tx, ty;
	string id, com = "", t;
	cin >> N >> M >> C;
	vector<vector<pair<int, int>>> v(26);

	for (int i = 0; i < N; i++)
	{
		cin >> t;
		for (int j = 0; j < M; j++)
		{
			v[t[j] - 'a'].push_back({ i, j });
		}
	}
	cin >> id;

	while (v[id[cnt] - 'a'].size())
	{
		if (cnt == 0)
		{
			if (!check(v, id))
				break;
		}
		min = 2501;
		min_i = 0;
		temp = v[id[cnt] - 'a'].back();
		v[id[cnt] - 'a'].pop_back();
		/*for (int i = 0; i < v[id[cnt] - 'a'].size(); i++)
		{
			if (min > abs(x - v[id[cnt] - 'a'][i].second) + abs(x - v[id[cnt] - 'a'][i].first))
			{
				min = abs(x - v[id[cnt] - 'a'][i].second) + abs(x - v[id[cnt] - 'a'][i].first);
				temp = v[id[cnt] - 'a'][i];
				min_i = i;
			}
		}
		v[id[cnt] - 'a'].erase(v[id[cnt] - 'a'].begin() + min_i);*/
		tx = x;
		ty = y;
		if (x - temp.second >= 0)
		{
			for (int i = 0; i < (x - temp.second); i++)
			{
				com += 'L';
				tx--;
			}
		}
		else
		{
			for (int i = 0; i < abs(x - temp.second); i++)
			{
				com += 'R';
				tx++;
			}
		}
		if (y - temp.first >= 0)
		{
			for (int i = 0; i < (y - temp.first); i++)
			{
				com += 'U';
				ty--;
			}
		}
		else
		{
			for (int i = 0; i < abs(y - temp.first); i++)
			{
				com += 'D';
				ty++;
			}
		}
		x = tx;
		y = ty;
		com += 'P';
		cnt++;
		if (cnt == id.size())
		{
			cnt = 0;
			up++;
		}
	}
	for (int i = 0; i < M - x - 1; i++)
		com += 'R';
	for (int i = 0; i < N - y - 1; i++)
		com += 'D';
	cout << up << ' ' << com.size() << '\n' << com;
	return 0;
}