// 스택 수열 못품
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, cnt = 0, num;
	int ary[100000] = { 0 };
	vector <char> v;
	stack <int> s;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		ary[i] = num;
	}

	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			while (cnt != ary[0])
			{
				s.push(cnt++ + 1);
				v.push_back('+');
			}
			v.push_back('-');
			s.pop();
		}
		else if (cnt == N)
		{
			while (i < N)
			{
				if (ary[i] == s.top())
				{
					v.push_back('-');
					s.pop();
					i++;
				}
				else
				{
					cout << "NO";
					return 0;
				}
			}
		}
		else if (ary[i] < ary[i - 1])
		{
			if (ary[i] == s.top())
			{
				v.push_back('-');
				s.pop();
			}
			else
			{
				cout << "NO";
				return 0;
			}
		}
		else if (ary[i] > ary[i - 1])
		{
			while (cnt != ary[i])
			{
				s.push(cnt++ + 1);
				v.push_back('+');
			}
			v.push_back('-');
			s.pop();
		}
	}
	
	for (int i = 0; i < N * 2; i++)
		cout << v[i] << '\n';

	return 0;
}