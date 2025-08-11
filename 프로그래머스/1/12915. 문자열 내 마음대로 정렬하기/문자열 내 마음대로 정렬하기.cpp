#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> solution(vector<string> strings, int n)
{
	vector<string> answer;

	auto cmp = [n](string a, string b) {
		if (a[n] != b[n])
			return a[n] < b[n];
		else
			return a < b;
		};

	sort(strings.begin(), strings.end(), cmp);

	answer = strings;

	return answer;
}