#include <bits/stdc++.h>
using namespace std;

int N;
stack <char> st;
string x;
bool check;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		st = stack<char>();
		check = true;
		cin >> x;

		for (int j = 0; j < x.size(); j++)
		{
			if (x[j] == '(') st.push('(');
			else
			{
				if (st.empty())
				{
					check = false;
					break;
				}
				else st.pop();
			}
		}

		cout << (check && st.empty() ? "YES\n" : "NO\n");
	}

	return 0;
}