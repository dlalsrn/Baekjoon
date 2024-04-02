#include <bits/stdc++.h>
using namespace std;

int N;
string x, str;
bool check;
vector <queue <string>> v;
vector <string> ans;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;
	cin.ignore();

	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		getline(cin, x);
		istringstream ss(x);
		while (getline(ss, str, ' ')) v[i].push(str);
	}

	getline(cin, x);
	istringstream ss(x);
	while (getline(ss, str, ' ')) ans.push_back(str);

	for (int i = 0; i < ans.size(); i++)
	{
		check = false;
		for (int j = 0; j < N; j++)
		{	
			if (!v[j].empty() && (v[j].front() == ans[i]))
			{
				check = true;
				v[j].pop();
				break;
			}
		}
		if (check) continue;
		else
		{
			cout << "Impossible";
			return 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (!v[i].empty())
		{
			cout << "Impossible";
			return 0;
		}
	}

	cout << "Possible";

	return 0;
}