// ZOAC 5
// 22.12.22
#include <iostream>
using namespace std;

int main(void)
{
	string x;
	int cnt = 1;
	cin >> x;
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] == x[i + 1])
			cnt++;
		else
			break;
	}
	cout << cnt;
	return 0;
}