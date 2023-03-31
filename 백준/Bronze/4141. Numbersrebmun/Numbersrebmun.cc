#include <iostream>
#include <string>
using namespace std;

int T;
string ans, x;

int main(void)
{
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> x;

		ans = "";

		for (int i = 0; i < x.size(); i++)
		{
			int v = toupper(x[i]);
			if (v < 68)
				ans += "2";
			else if (v < 71)
				ans += "3";
			else if (v < 74)
				ans += "4";
			else if (v < 77)
				ans += "5";
			else if (v < 80)
				ans += "6";
			else if (v < 84)
				ans += "7";
			else if (v < 87)
				ans += "8";
			else if (v < 91)
				ans += "9";
		}

		bool TF = true;
		for (int i = 0; i < ans.size() / 2; i++)
		{
			if (ans[i] != ans[ans.size() - 1 - i])
			{
				TF = false;
				break;
			}
		}

		cout << (TF ? "YES" : "NO") << '\n';
	}

	return 0;
}