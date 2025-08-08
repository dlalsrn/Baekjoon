#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool CheckNumOfDivisor(int n)
{
	int cnt = 0;

	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			cnt++;
		}
	}

	return cnt % 2;
}

int solution(int left, int right)
{
	int answer = 0;

	for (int i = left; i <= right; i++)
	{
		if (CheckNumOfDivisor(i))
		{
			answer -= i;
		}
		else
		{
			answer += i;
		}
	}

	return answer;
}