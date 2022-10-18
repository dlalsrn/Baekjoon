// 그룹 단어 체커
#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

int main(void)
{
	int N, cnt = 0;
	int ary[26] = { 0 };
	string voca;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> voca;
		for (int j = 0; voca.length(); j++)
		{
			if (voca.length() == 1)
			{
				cnt++;
				break;
			}
			if (ary[voca[j] - 97] == 0)
				ary[voca[j] - 97]++;
			else if (ary[voca[j] - 97] != 0 && voca[j] != voca[j - 1])
				break;
			if (j + 1 == voca.length())
				cnt++;
		}
		memset(ary, 0, sizeof(int) * 26);
	}
	cout << cnt;
	return 0;
}