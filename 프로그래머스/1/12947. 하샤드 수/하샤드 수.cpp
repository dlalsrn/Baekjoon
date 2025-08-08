#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solution(int x) 
{
	bool answer = 0;
	
	int t = x;
	int sum = 0;

	while (t)
	{
		sum += t % 10;
		t /= 10;
	}

	answer = (x % sum == 0);

	return answer;
}