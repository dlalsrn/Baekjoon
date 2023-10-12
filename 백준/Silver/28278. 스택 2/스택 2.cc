#include <iostream>
#include <stack>
using namespace std;

int N, a, b;
stack <int> s;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a;

		if (a == 1)
		{
			cin >> b;
			s.push(b);
		}
		else if (a == 2)
		{
			if (s.empty())
				cout << -1 << '\n';
			else
			{
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (a == 3)
			cout << s.size() << '\n';
		else if (a == 4)
			cout << s.empty() << '\n';
		else
			cout << (s.empty() ? -1 : s.top()) << '\n';
	}

	return 0;
}