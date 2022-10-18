#include <string>
#include <iostream>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	string str;
	cin >> str;
	string ans = "";
	int len = str.size();

	for (int i = 1; i < len - 1; i++)
	{
		for (int s = i + 1; s < len; s++)
		{
			string temp = "";
			for (int j = i - 1; j >= 0; j--)
				temp += str[j];
			for (int j = s - 1; j >= i; j--)
				temp += str[j];
			for (int j = len - 1; j >= s; j--)
				temp += str[j];

			if (ans == "")
				ans = temp;
			if (ans > temp)
				ans = temp;
		}
	}
	cout << ans << '\n';
    return 0;
 }