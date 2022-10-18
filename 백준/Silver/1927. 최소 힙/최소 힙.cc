#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <functional>
using namespace std;

int main(void)
{
	priority_queue <int, vector<int>, greater<int>> q;
	int N;
	scanf(" %d", &N);

	for (int i = 0; i < N; i++)
	{
		int num;
		scanf(" %d", &num);
		if (num != 0)
			q.push(num);
		else
		{
			if (q.empty())
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n", q.top());
				q.pop();
			}
		}
	}
    return 0;
}