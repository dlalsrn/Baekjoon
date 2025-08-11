#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b)
{
	if (a < b)
	{
		swap(a, b);
	}

	return b == 0 ? a : gcd(b, a % b);
}

vector<int> solution(int n, int m)
{
	vector<int> answer;

	answer.push_back(gcd(n, m));
	answer.push_back(n * m / gcd(n, m));

	return answer;
}