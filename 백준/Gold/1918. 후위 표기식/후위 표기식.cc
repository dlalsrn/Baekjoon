#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	stack <char> s;
	string x;
	string total = "";
	cin >> x;
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] >= 65)
			total += x[i];
		else
		{
			if (s.empty())
				s.push(x[i]);
			else
			{
				if (x[i] == '*' || x[i] == '/')
				{
					if (s.top() == '/' || s.top() == '*')
					{
						total += s.top();
						s.pop();
					}
					s.push(x[i]);
				}
				else if (x[i] == '-' || x[i] == '+')
				{
					while (!s.empty() && s.top() != '(')
					{
						total += s.top();
						s.pop();
					}
					s.push(x[i]);
				}
				else if (x[i] == '(')
					s.push(x[i]);
				else if (x[i] == ')')
				{
					while (s.top() != '(')
					{
						total += s.top();
						s.pop();
					}
					s.pop();
				}
			}
		}
	}

	while (!s.empty())
	{
		total += s.top();
		s.pop();
	}
	cout << total;
	return 0;
}