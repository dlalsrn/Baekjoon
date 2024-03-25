#include <bits/stdc++.h>
using namespace std;

string x;
int N;
char ch, t;
stack <char> L, R;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> x >> N;

	for (int i = 0; i < x.size(); i++) L.push(x[i]);

	for (int i = 0; i < N; i++)
	{
		cin >> ch;

		if (ch == 'L' && !L.empty())
		{
			R.push(L.top());
			L.pop();
		}
		else if (ch == 'D' && !R.empty())
		{
			L.push(R.top());
			R.pop();
		}
		else if (ch == 'B' && !L.empty()) L.pop();
		else if (ch == 'P')
		{
			cin >> t;
			L.push(t);
		}
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

	return 0;
}