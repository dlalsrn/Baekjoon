#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solution(vector<vector<int>> sizes)
{
	int answer = 0;
	vector<int> largeLen;
	vector<int> smallLen;

	for (int i = 0; i < sizes.size(); i++)
	{
		sort(sizes[i].begin(), sizes[i].end());
		smallLen.push_back(sizes[i][0]);
		largeLen.push_back(sizes[i][1]);
	}

	int width = *max_element(smallLen.begin(), smallLen.end());
	int height = *max_element(largeLen.begin(), largeLen.end());
	answer = width * height;

	return answer;
}