#include <bits/stdc++.h>
using namespace std;

string x;
stack <char> s;
bool check = false;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	getline(cin, x);

	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == '<')
		{
			while (!s.empty())
			{
				cout << s.top();
				s.pop();
			}
			check = true;
			s.push(x[i]);
		}
		else if (x[i] == '>')
		{
			stack <char> t;
			while (s.top() != '<')
			{
				t.push(s.top());
				s.pop();
			}
			t.push(s.top());
			s.pop();
			while (!t.empty())
			{
				cout << t.top();
				t.pop();
			}
			cout << x[i];
			check = false;
		}
		else if (x[i] == ' ')
		{
			if (check) s.push(x[i]);
			else
			{
				while (!s.empty())
				{
					cout << s.top();
					s.pop();
				}
				cout << x[i];
			}
		}
		else s.push(x[i]);
	}

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}

	return 0;
}