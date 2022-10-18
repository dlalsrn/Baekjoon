#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, num;
	char commend;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		multiset <int> s;
		for (int k = 0; k < N; k++)
		{
			cin >> commend >> num;
			if (commend == 'I')
			{
				s.insert(num);
			}
			else
			{
				if (!s.empty())
				{
					if (num == 1)
					{
						auto it = s.end();
						s.erase(--it);
					}
					else
						s.erase(s.begin());
				}
			}
		}

		if (s.empty())
			cout << "EMPTY\n";
		else
		{
			auto it = s.end();
			cout << *--it << ' ' << *s.begin() << '\n';
		}
	}
	return 0;
}