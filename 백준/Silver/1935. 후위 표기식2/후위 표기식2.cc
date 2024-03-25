#include <bits/stdc++.h>
using namespace std;

int N, cnt = 0;
double t;
string x;
stack <double> st;
map <char, int> m;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	cout << fixed;
	cout.precision(2);

	cin >> N >> x;

	for (int i = 0; i < N; i++)
	{
		cin >> t;
		m[65 + i] = t;
	}

	for (int i = 0; i < x.size(); i++)
	{
		if (65 <= x[i] && x[i] <= 90) st.push(m[x[i]]);
		else
		{
			double b = st.top();
			st.pop();
			double a = st.top();
			st.pop();
			if (x[i] == '+') st.push(a + b);
			else if (x[i] == '-') st.push(a - b);
			else if (x[i] == '*') st.push(a * b);
			else st.push(a / b);
		}
	}

	cout << st.top();

	return 0;
}