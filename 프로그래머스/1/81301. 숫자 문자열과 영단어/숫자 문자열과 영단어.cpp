#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solution(string s)
{
	string answer = "";
	
	for (int i = 0; i < s.size(); i++)
	{
		if (isdigit(s[i])) // 숫자라면
		{
			answer += s[i];
		}
		else // 문자라면 check
		{
			if (s[i] == 'z') // zero
			{
				answer += '0';
				i += 3;
			}
			else if (s[i] == 'o') // one
			{
				answer += '1';
				i += 2;
			}
			else if (s[i] == 't')
			{
				if (s[i + 1] == 'w') // two
				{
					answer += '2';
					i += 2;
				}
				else // three
				{
					answer += '3';
					i += 4;
				}
			}
			else if (s[i] == 'f')
			{
				if (s[i + 1] == 'o') // four
				{
					answer += '4';
					i += 3;
				}
				else // five
				{
					answer += '5';
					i += 3;
				}
			}
			else if (s[i] == 's')
			{
				if (s[i + 1] == 'i') // six
				{
					answer += '6';
					i += 2;
				}
				else // seven
				{
					answer += '7';
					i += 4;
				}
			}
			else if (s[i] == 'e') // eight
			{
				answer += '8';
				i += 4;
			}
			else if (s[i] == 'n') // nine
			{
				answer += '9';
				i += 3;
			}
		}
	}

	return stoi(answer);
}