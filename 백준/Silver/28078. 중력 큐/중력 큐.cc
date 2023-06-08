#include <iostream>
#include <queue>
#include <map>
using namespace std;

int N, cnt_b = 0, cnt_w = 0, dir = 0; // 큐의 뒤쪽이 왼쪽, 위, 오른쪽, 아래
deque <int> dq;
map <char, int> m;
string x;
char ch;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	m['b'] = 0;
	m['w'] = 1;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x == "push")
		{
			cin >> ch;
			dq.push_front(m[ch]);
			if (m[ch])
				cnt_w++;
			else
				cnt_b++;
			if (dir == 3 && !m[ch])
			{
				dq.pop_front();
				cnt_b--;
			}
			else if (!m[ch] && (dir == 1 || dir == 3) && dq.size() == 1)
			{
				dq.pop_front();
				cnt_b--;
			}
		}
		else if (x == "pop")
		{
			if (!dq.empty())
			{
				if (dq.back())
					cnt_w--;
				else
					cnt_b--;
				dq.pop_back();
				if (dir == 1)
				{
					while (!dq.empty() && !dq.back())
					{
						dq.pop_back();
						cnt_b--;
					}
				}
			}
		}
		else if (x == "rotate")
		{
			cin >> ch;
			if (ch == 'r')
				dir = (dir + 1) % 4;
			else
				dir = (dir + 3) % 4;
			if (dir == 1)
			{
				while (!dq.empty() && !dq.back())
				{
					dq.pop_back();
					cnt_b--;
				}
			}
			else if (dir == 3)
			{
				while (!dq.empty() && !dq.front())
				{
					dq.pop_front();
					cnt_b--;
				}
			}

		}
		else
		{
			cin >> ch;
			if (m[ch])
				cout << cnt_w << '\n';
			else
				cout << cnt_b << '\n';
		}
	}
}