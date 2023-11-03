#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	string x;
	double H = 0, S = 0, ans;

	getline(cin, x);
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == ' ')
			continue;
		if (x[i] == 'A')
		{
			H++;
			S++;
		}
		else if (x[i] == 'H' || x[i] == 'P' || x[i] == 'Y')
			H++;
		else if (x[i] == 'S' || x[i] == 'D')
			S++;
	}

	if (H == 0 && S == 0)
		cout << "50.00";
	else
	{
		ans = (H / (H + S)) * 100;
		ans += 1e-10;
		printf("%.2f", ans);
	}

	return 0;
}