#include <iostream>
#include <set>
using namespace std;

string x;
set <string> s;

int main(void)
{
	cin >> x;

	for (int i = 0; i < x.size(); i++)
		for (int j = 1; i + j <= x.size(); j++)
			s.insert(x.substr(i, j));

	cout << s.size();

	return 0;
}