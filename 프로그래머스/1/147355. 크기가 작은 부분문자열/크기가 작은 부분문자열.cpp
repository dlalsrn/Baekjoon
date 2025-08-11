#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solution(string t, string p)
{
	int answer = 0;
	int size = p.size();

	for (int i = 0; i < t.size() - size + 1; i++)
	{
		string sub = t.substr(i, size);
		bool check = true;

		for (int j = 0; j < size; j++)
		{
			if (sub[j] < p[j])
			{
				break;
			}
			else if (sub[j] > p[j])
			{
				check = false;
				break;
			}
		}

		answer += check;
	}

	return answer;
}