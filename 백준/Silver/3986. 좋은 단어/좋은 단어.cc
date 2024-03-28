#include <bits/stdc++.h>
using namespace std;

int T, ans = 0;
string x;
stack <char> st;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> x;
		st = stack<char>();

		for (int i = 0; i < x.size(); i++)
		{
			if (!st.empty() && st.top() == x[i]) st.pop();
			else st.push(x[i]);
		}

		if (st.empty()) ans++;
	}

	cout << ans;

	return 0;
}