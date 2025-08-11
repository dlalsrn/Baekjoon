#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solution(string s) 
{
	bool answer = true;
	
	if (s.size() == 4 || s.size() == 6)
	{
		for (char x : s)
		{
			if (x < '0' || x > '9')
			{
				answer = false;
				break;
			}
		}
	}
	else
	{
		answer = false;
	}

	return answer;
}