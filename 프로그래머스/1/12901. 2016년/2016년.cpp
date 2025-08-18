#include <bits/stdc++.h>
using namespace std;

string day[] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
int month[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 };

string solution(int a, int b)
{
    string answer = "";
    int days = 0;

    for (int i = 0; i < a - 1; i++)
    {
        days += month[i];
    }

    days += b - 1;
    answer = day[days % 7];

    return answer;
}