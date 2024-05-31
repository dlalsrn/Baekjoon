#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
string x;
stack <int> st;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> x;

	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == '(') st.push(-1);
		else if (x[i] == ')')
		{
			int t = 0;
			while (!st.empty() && st.top() != -1)
			{
				t += st.top();
				st.pop();
			}
			st.pop();
			t *= (st.top());
			st.pop();
			st.push(t);
		}
		else
		{
			if (x[i + 1] == '(') st.push(x[i] - '0');
			else st.push(1);
		}
	}

	while (!st.empty())
	{
		cnt += st.top();
		st.pop();
	}

	cout << cnt;

	return 0;
}