#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
	vector<int> answer;

	for (int i = 0; i < commands.size(); i++)
	{
		int a = commands[i][0] - 1;
		int b = commands[i][1] - 1;
		int k = commands[i][2] - 1;
		vector<int> temp;
		
		for (int j = a; j <= b; j++)
		{
			temp.push_back(array[j]);
		}

		sort(temp.begin(), temp.end());

		answer.push_back(temp[k]);
	}

	return answer;
}