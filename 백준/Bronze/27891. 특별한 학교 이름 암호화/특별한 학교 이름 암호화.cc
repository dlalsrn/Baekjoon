#include <iostream>
using namespace std;

string x;

int main(void)
{
	cin >> x;

	for (int i = 0; i < 26; i++)
	{
		if (x == "northlondo")
		{
			cout << "NLCS";
			break;
		}
		else if (x == "branksomeh")
		{
			cout << "BHA";
			break;
		}
		else if (x == "koreainter")
		{
			cout << "KIS"; 
			break;
		}
		else if (x == "stjohnsbur")
		{
			cout << "SJA";
			break;
		}

		for (int j = 0; j < x.size(); j++)
		{
			x[j] = x[j] + 1;
			if (x[j] > 122)
				x[j] = 97;
		}
	}

	return 0;
}