// 단어 공부
#include <iostream>
using namespace std;

int main(void)
{
	string a;
	int ary[26] = { 0 };
	int max = 0, cnt = 0;
	cin >> a;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] >= 97)
			ary[a[i] - 97]++;
		else
			ary[a[i] - 65]++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (ary[i] > max)
			max = ary[i];
	}
	for (int i = 0; i < 26; i++)
	{
		if (ary[i] == max)
			cnt++;
	}

	if (cnt == 1)
	{
		for (int i = 0; i < 26; i++)
			if (ary[i] == max)
				printf("%c", i + 65);
	}
	else
		cout << "?";
	return 0;
}