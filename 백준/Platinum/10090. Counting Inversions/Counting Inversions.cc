// Counting Inversions
#include <iostream>
#include <vector>
using namespace std;
long long cnt = 0;

void merge_sort(vector <int>& v, vector<int>& total, int start, int end, int mid)
{
	int left, right, total_i;
	left = start;
	right = mid + 1;
	total_i = start;
	while (left <= mid && right <= end)
	{
		if (v[left] > v[right])
		{
			total[total_i++] = v[right++];
			cnt += mid - left + 1;
		}
		else
			total[total_i++] = v[left++];
	}

	if (left <= mid)
	{
		for (int i = left; i <= mid; i++)
		{
			total[total_i++] = v[left++];
		}
	}
	if (right <= end)
		for (int i = right; i <= end; i++)
			total[total_i++] = v[right++];

	for (int i = start; i <= end; i++)
		v[i] = total[i];
}

void merge(vector <int>& v, vector<int>& total, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		merge(v, total, start, mid);
		merge(v, total, mid + 1, end);
		merge_sort(v, total, start, end, mid);
	}
}

int main(void)
{
	int N, num;
	cin >> N;
	vector <int> v(N);
	vector <int> total(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	merge(v, total, 0, N - 1);
	cout << cnt;
	return 0;
}