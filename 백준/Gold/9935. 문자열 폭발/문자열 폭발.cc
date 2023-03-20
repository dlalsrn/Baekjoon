#include <iostream>
#include <string>
using namespace std;

string ans = "", x, boom;
int cnt;
int main(void)
{
	cin >> x >> boom;

	for (int i = 0; i < x.size(); i++)
	{
		ans += x[i];
		if (ans.size() >= boom.size())
		{
			if (ans.substr(ans.size() - boom.size(), boom.size()) == boom)
			{
				cnt = 0;
				while (cnt != boom.size())
				{
					ans.pop_back();
					cnt++;
				}
			}
		}
	}

	if (!ans.size())
		cout << "FRULA";
	else
		cout << ans;

	return 0;
}