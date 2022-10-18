#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string x, temp = "";
	bool TF;
	cin >> x;
	for (int i = 0; i < x.length(); i++)
	{
		TF = false;
		int j = x.length() - 1;
		for (int j = i, k = x.length() - 1; j < k; j++, k--)
		{
			if (x[j] != x[k])
			{
				temp = x[i] + temp;
				TF = true;
				break;
			}
		}
		if (!TF)
			break;
	}
	cout << (x + temp).length();
	return 0;
}