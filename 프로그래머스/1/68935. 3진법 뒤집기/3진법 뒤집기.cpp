#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solution(int n)
{
	int answer = 0;
	string s = "";

	while (n)
	{
		s = to_string(n % 3) + s;
		n /= 3;
	}

	cout << s;

	for (int i = 0; i < s.size(); i++)
	{
		answer += (s[i] - '0') * pow(3, i);
	}

	return answer;
}