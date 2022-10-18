#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector <pair<int, pair<int, string>>> v;

	for (int i = 0; i < n; i++)
	{
		int a;
		string b;
		cin >> a >> b;
		v.push_back(make_pair(a, make_pair(i, b)));
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		cout << v[i].first << ' ' << v[i].second.second << '\n';
    return 0;
}