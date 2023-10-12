#include <iostream>
#include <stack>
#include <string>
using namespace std;

string x;
stack <char> s;
bool TF;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	while (true)
	{
		getline(cin, x);
		s = stack<char>();
		TF = true;

		if (x == ".")
			break;
		for (int i = 0; i < x.size(); i++)
		{
			if (x[i] == '(' || x[i] == '[')
				s.push(x[i]);
			else if (x[i] == ')' || x[i] == ']')
			{
				if (s.empty() || (s.top() == '(' && x[i] != ')') || (s.top() == '[' && x[i] != ']'))
				{
					TF = false;
					break;
				}
				s.pop();
			}
		}

		if (TF && s.empty())
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}