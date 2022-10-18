#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main(void)
{
	int N;
	int max = 0;
	cin >> N;
	vector <pair<string, int>> v;
	vector <string> total;
	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		for (int s = 0; s < v.size(); s++)
		{
			if (v[s].first == a)
				v[s].second++;
		}
		v.push_back(make_pair(a, 1));
	}
	for (int i = 0; i < N; i++)
	{
		if (max < v[i].second)
			max = v[i].second;
	}
	for (int i = 0; i < N; i++)
	{
		if (v[i].second == max)
			total.push_back(v[i].first);
	}
	sort(total.begin(), total.end());
	cout << total[0];
    return 0;
}