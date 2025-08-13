#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<string, int> m;

vector<string> solution(vector<string> players, vector<string> callings)
{
	vector<string> answer;

	for (int i = 0; i < players.size(); i++)
	{
		m[players[i]] = i;
	}

	for (int i = 0; i < callings.size(); i++)
	{
		int index = m[callings[i]];
		swap(players[index], players[index - 1]);
		swap(m[players[index]], m[players[index - 1]]);
	}

	answer = players;

	return answer;
}