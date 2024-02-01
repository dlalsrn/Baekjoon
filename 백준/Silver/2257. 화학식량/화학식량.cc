#include <bits/stdc++.h>
using namespace std;

stack <int> st;
int ans = 0;
string x;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> x;

	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == ')')
		{
			int cnt = 0;

			while (!st.empty() && st.top() != -1)
			{
				cnt += st.top();
				st.pop();
			}

			if (!st.empty())
				st.pop();

			st.push(cnt);
		}
		else
		{
			if (x[i] == '(') st.push(-1);
			else if (x[i] == 'H') st.push(1);
			else if (x[i] == 'C') st.push(12);
			else if (x[i] == 'O') st.push(16);
			else st.top() *= x[i] - 48;
		}
	}

	while (!st.empty())
	{
		ans += st.top();
		st.pop();
	}

	cout << ans;

	return 0;
}
