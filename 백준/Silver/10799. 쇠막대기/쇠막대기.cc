#include <bits/stdc++.h>
using namespace std;

int ans = 0;
string x;
stack <char> st;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> x;

	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == '(') st.push(x[i]);
		else
		{
			if (x[i - 1] == '(')ans += st.size() - 1;
			else ans += 1;
			st.pop();
		}
	}

	cout << ans;

	return 0;
}