// 크로아티아 알파벳
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	string replace[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	string str;
	int cnt = 0;
	cin >> str;
	for (int i = 0; i < 8; i++)
	{
		string temp = replace[i];
		while (str.find(temp) != string::npos)
		{
			str.replace(str.find(temp), temp.length(), " ");
			cnt++;
		}
	}
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	cout << str.length() + cnt;
	return 0;
}