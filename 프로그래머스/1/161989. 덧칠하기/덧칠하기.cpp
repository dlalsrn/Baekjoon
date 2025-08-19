#include <bits/stdc++.h>
using namespace std;

int solution(int n, int m, vector<int> section)
{
    int answer = 1;
    int start = section[0];

    for (int i = 1; i < section.size(); i++)
    {
        if (start + m <= section[i])
        {
            answer++;
            start = section[i];
        }
    }

    return answer;
}