#include <iostream>
#include <map>
using namespace std;

map <char, bool> m;
string x;

int main(void)
{
	cin >> x;

	for (int i = 0; i < x.size(); i++)
		m[x[i]] = true;

	if (m['M'] && m['O'] && m['B'] && m['I'] && m['S'])
		cout << "YES";
	else
		cout << "NO";

	return 0;
}