// 괄호
// 24.04.01
// stack
#include <bits/stdc++.h>
using namespace std;

int N;
stack <char> st;
string x;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		st = stack<char>();
		cin >> x;

		for (int j = 0; j < x.size(); j++)
		{
			st.push(x[i]);

			if (x[j] == ')')
			{
				if (st.size() >= 2)
				{
					st.pop();
					st.pop();
				}
				else break;
			}
		}

		cout << (st.empty() ? "YES\n" : "NO\n");
	}

	return 0;
}