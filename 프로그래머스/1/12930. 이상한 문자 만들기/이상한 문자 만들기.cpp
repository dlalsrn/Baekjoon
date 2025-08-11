#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solution(string s)
{
	string answer = "";
	string temp = "";

	for (int i = 0; i < s.size(); i++)
	{
		temp += s[i];

		if (s[i] == ' ' || i == s.size() - 1)
		{
			for (int j = 0; j < temp.size(); j++)
			{
				if (j % 2) // 홀수
				{
					temp[j] = tolower(temp[j]);
				}
				else // 짝수
				{
					temp[j] = toupper(temp[j]);
				}
			}
			answer += temp;
			temp = "";
		}
	}

	return answer;
}