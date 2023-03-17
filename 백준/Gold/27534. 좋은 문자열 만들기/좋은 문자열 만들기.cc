#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int T, N;
int left_zero, right_zero;
int left_one, right_one;
string x;

int main(void)
{
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N >> x;

		if (x.size() == 1 || x.size() == 3)
		{
			cout << -1 << '\n';
			continue;
		}

		left_zero = x.size();
		right_zero = -1;
		left_one = x.size();
		right_one = -1;

		for (int i = 0; i < x.size(); i++)
		{
			if (x[i] == '0')
			{
				left_zero = min(left_zero, i);
				right_zero = max(left_zero, i);
			}
			else
			{
				left_one = min(left_one, i);
				right_one = max(left_one, i);
			}
		}

		if ((right_zero == -1 && left_zero == x.size()) || (right_one == -1 && left_one == x.size())) // 0이나 1 둘 중 하나가 하나도 없을 때
		{
			if (x.size() == 2)
				cout << 1 << '\n';
			else
				cout << 2 << '\n';
		}
		else if (right_zero - left_zero == right_one - left_one) // 0구간과 1구간의 길이가 같을 때
			cout << 0 << '\n';
		else if (right_zero < left_one || right_one < left_zero) // 0과 1 구간이 겹치지 않을 때
		{
			if (abs((right_zero - left_zero) - (right_one - left_one)) == 1)
				cout << 2 << '\n';
			else
				cout << 1 << '\n';
		}
		else if (left_zero < left_one && right_one < right_zero) // 0 구간이 1구간을 포함하고 있을 때
		{
			if (left_one == 1 && right_one == x.size() - 2)
				cout << 2 << '\n';
			else if (left_one == 1 || right_one == x.size() - 2)
				cout << 1 << '\n';
			else
				cout << 2 << '\n';
		}
		else if (left_one < left_zero && right_zero < right_one) // 1 구간이 0구간을 포함하고 있을 때
		{
			if (left_zero == 1 && right_zero == x.size() - 2)
				cout << 2 << '\n';
			else if (left_zero == 1 || right_zero == x.size() - 2)
				cout << 1 << '\n';
			else
				cout << 2 << '\n';
		}
		else // 1구간과 0구간이 겹칠 때
		{
			cout << 1 << '\n';
		}
	}

	return 0;
}