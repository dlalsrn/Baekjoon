#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solution(int n) 
{
	int answer = 0;

	for (ll i = n; i != 1; answer++)
	{
		if (answer > 500)
		{
			break;
		}

		if (i % 2 == 0)
		{
			i /= 2;
		}
		else
		{
			i = i * 3 + 1;
		}
	}

	return (answer <= 500 ? answer : -1);
}