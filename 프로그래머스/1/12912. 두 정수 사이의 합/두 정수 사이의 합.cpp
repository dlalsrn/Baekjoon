#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solution(int a, int b) 
{
	ll answer = 0;

	if (a > b)
	{
		swap(a, b);
	}
	
	for (ll i = a; i <= b; i++)
	{
		answer += i;
	}

	return answer;
}