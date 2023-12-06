#include <bits/stdc++.h>
using namespace std;

string x;
stack <char> s;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> x;

	for (int i = x.size() - 1; i >= 0; i--)
	{
		s.push(x[i]);
		
		if (s.size() >= 4)
		{
			char a, b, c, d;
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			c = s.top();
			s.pop();
			d = s.top();
			s.pop();
			if (a == 'P' && b == 'P' && c == 'A' && d == 'P')
				s.push('P');
			else
			{
				s.push(d);
				s.push(c);
				s.push(b);
				s.push(a);
			}
		}
	}

	cout << ((s.size() == 1 && s.top() == 'P') ? "PPAP" : "NP");

	return 0;
}