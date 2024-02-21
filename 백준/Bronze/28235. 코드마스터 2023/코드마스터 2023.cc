#include <bits/stdc++.h>
using namespace std;

string x;

int main(void)
{
	cin >> x;

	if (x == "SONGDO") cout << "HIGHSCHOOL";
	else if (x == "CODE") cout << "MASTER";
	else if (x == "ALGORITHM") cout << "CONTEST";
	else cout << "0611";

	return 0;
}