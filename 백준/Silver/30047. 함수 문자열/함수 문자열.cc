#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string x;
stack <int> s;

int main(void)
{
	cin >> x;

	for (int i = x.size() - 1; i >= 0; i--)
	{
		if (x[i] == 'x')
			s.push(0);
		else if (x[i] == 'g')
		{
			if (s.empty())
			{
				cout << -1;
				return 0;
			}
			s.top()++;
		}
		else
		{
			if (s.size() < 2)
			{
				cout << -1;
				return 0;
			}
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			s.push(min(a, b));
		}
	}

	cout << (s.size() == 1 ? s.top() : -1);

	return 0;
}