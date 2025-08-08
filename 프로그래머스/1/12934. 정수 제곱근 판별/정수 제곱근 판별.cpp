#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solution(ll n) 
{
	ll answer = 0;

	if (sqrt(double(n)) == floor(sqrt(double(n))))
	{
		answer = pow(sqrt(double(n)) + 1, 2);
	}
	else
	{
		answer = -1;
	}

	return answer;
}