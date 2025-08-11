#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solution(string s, int n)
{
	string answer = "";

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			answer += ' ';
			continue;
		}
		else
		{
			char t = (s[i] >= 'a') ? 'a' : 'A';
			answer += (s[i] - t + n) % 26 + t;
		}
	}

	return answer;
}