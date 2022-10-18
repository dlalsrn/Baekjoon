#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector <pair<int, pair<int, string>>> v;

	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		int sum = 0;
		for (int s = 0; s < a.size(); s++)
		{
			if (0 <= a.c_str()[s] - 48 && a.c_str()[s] - 48 <= 9)
				sum += a.c_str()[s] - 48;
		}
		v.push_back(make_pair(a.size(), make_pair(sum, a)));
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		cout << v[i].second.second << '\n';
    return 0;
}