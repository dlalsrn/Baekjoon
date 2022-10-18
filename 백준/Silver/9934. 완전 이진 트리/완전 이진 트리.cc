#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;

void Print_Node(int depth, int arr[], int root, int temp)
{
	temp /= 2;
	if (depth == 0)
	{
		cout << arr[root] << " ";
	}
	else
	{
		Print_Node(depth - 1, arr, root - (temp / 2) - 1, temp);
		Print_Node(depth - 1, arr, root + (temp / 2) + 1, temp);
	}
}
int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N, buliding[1024] = { 0 };
	cin >> N;
	int len = 0, num;

	for (int i = 0; i < pow(2, N) - 1; i++)
	{
		cin >> num;
		buliding[i] = num;
		len++;
	}

	for (int i = 0; i < N; i++)
	{
		Print_Node(i, buliding, len/2, len);
		cout << "\n";
	}
    return 0;
}