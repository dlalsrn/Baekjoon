#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector <pair<int, pair<int, pair<int, string>>>> v;

	for (int i = 0; i < n; i++)
	{
		string name;
		int kor, eng, math;
		cin >> name >> kor >> eng >> math;
		v.push_back(make_pair(100 - kor, make_pair(eng, make_pair(100 - math, name))));
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		cout << v[i].second.second.second << '\n';
    return 0;
}