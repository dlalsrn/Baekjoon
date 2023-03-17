#include <iostream>
#include <string>
using namespace std;

string x;
string ans;

int main(void)
{
	getline(cin, x);

	for (int i = 0; i < x.size() - 7; i++)
	{
		if (x.substr(i, 7) == "What is")
		{
			ans = "";
			for (int j = i + 7; j < x.size(); j++)
			{
				if (x[j] != '.' && x[j] != '?')
					ans += x[j];
				else
				{
					if (x[j] == '?')
						cout << "Forty-two is" + ans + "." << '\n';
					break;
				}
			}
		}
	}

	return 0;
}