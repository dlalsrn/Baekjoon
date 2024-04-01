#include <bits/stdc++.h>
using namespace std;

string x;
stack <char> s;
bool check;

int main(void)
{
    cin.tie(0)->sync_with_stdio(false);

	while (true)
	{
		s = stack<char>();
		getline(cin, x);
		check = true;
		if (x == ".") break;

		for (int i = 0; i < x.size(); i++)
		{
			if (x[i] == '(' || x[i] == '[') s.push(x[i]);
			else if (x[i] == ')' || x[i] == ']')
			{
				if (s.empty() || (s.top() == '(' && x[i] != ')') || (s.top() == '[' && x[i] != ']'))
				{
					check = false;
					break;
				}
				s.pop();
			}
		}

		cout << (check && s.empty() ? "yes\n" : "no\n");
	}

    return 0;
}