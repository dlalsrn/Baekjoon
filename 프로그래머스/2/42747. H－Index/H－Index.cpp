#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;
    sort(citations.begin(), citations.end());

    int mn = 0, mx = 10000;
    while (mn <= mx)
    {
        int mid = (mn + mx + 1) / 2;
        int upper = citations.end() - lower_bound(citations.begin(), citations.end(), mid);

        if (upper >= mid)
        {
            mn = mid + 1;
            answer = mid;
        }
        else
        {
            mx = mid - 1;
        }
    }

    return answer;
}

int main(void)
{
    cout << solution({ 3, 4 });
}