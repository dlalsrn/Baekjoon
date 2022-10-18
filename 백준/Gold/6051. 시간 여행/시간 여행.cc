#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<stack<int>> v;
	stack<int> s;
	int N, num;
	char x;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x == 'a')
		{
			cin >> num;
			s.push(num);
			v.push_back(s);
		}
		else if (x == 's')
		{
			s.pop();
			v.push_back(s);
		}
		else
		{
			cin >> num;
			if (num - 2 < 0)
				s = stack<int>();
			else
				s = v[num - 2];
			v.push_back(s);
		}
		if (s.empty())
			cout << -1 << '\n';
		else
			cout << s.top() << '\n';
	}
	return 0;
}