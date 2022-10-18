#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector <pair<int, string>> v;
	string voca;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> voca;
		v.push_back({ voca.length(), voca });
	}

	sort(v.begin(), v.end());
	cout << v[0].second << endl;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i-1].second != v[i].second)
			cout << v[i].second << endl;
	}

	return 0;
}