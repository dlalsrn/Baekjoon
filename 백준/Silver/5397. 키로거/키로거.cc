#include <bits/stdc++.h>
using namespace std;

int N, T;
string x;
stack <char> L, R;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> x;

		for (int i = 0; i < x.size(); i++)
		{
			if (x[i] == '<')
			{
				if (!L.empty())
				{
					R.push(L.top());
					L.pop();
				}
			}
			else if (x[i] == '>')
			{
				if (!R.empty())
				{
					L.push(R.top());
					R.pop();
				}
			}
			else if (x[i] == '-')
			{
				if (!L.empty()) L.pop();
			}
			else L.push(x[i]);
		}

		while (!L.empty())
		{
			R.push(L.top());
			L.pop();
		}

		while (!R.empty())
		{
			cout << R.top();
			R.pop();
		}

		cout << '\n';
	}

	return 0;
}