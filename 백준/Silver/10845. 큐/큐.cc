#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
	queue <int> qu;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		if (a == "push")
		{
			int n;
			cin >> n;
			qu.push(n);
		}
		else if (a == "front")
		{
			if (qu.empty())
				cout << "-1" << '\n';
			else
				cout << qu.front() << '\n';
		}
		else if (a == "back")
		{
			if (qu.empty())
				cout << "-1" << '\n';
			else
				cout << qu.back() << '\n';
		}
		else if (a == "size")
			cout << qu.size() << '\n';
		else if (a == "empty")
			cout << qu.empty() << '\n';
		else
		{
			if (qu.empty())
				cout << "-1" << '\n';
			else
			{
				cout << qu.front() << '\n';
				qu.pop();
			}
		}
	}
    return 0;
}