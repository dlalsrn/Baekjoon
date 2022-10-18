#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector <pair <int, int>> v;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back(make_pair(b, a));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		printf("%d %d \n", v[i].second, v[i].first);
}