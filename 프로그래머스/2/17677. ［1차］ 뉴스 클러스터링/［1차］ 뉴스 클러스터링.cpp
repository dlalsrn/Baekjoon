#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

bool IsChar(char a)
{
    if (0 <= a - 'a' && a - 'a' < 26)
    {
        return true;
    }
    else if (0 <= a - 'A' && a - 'A' < 26)
    {
        return true;
    }

    return false;
}

bool CheckChar(char a, char b)
{
    if (IsChar(a) && IsChar(b))
    {
        return true;
    }

    return false;
}

void CountSet(string str, unordered_map<string, int>& um)
{
    for (int i = 0; i < str.size() - 1; ++i)
    {
        if (CheckChar(str[i], str[i + 1]))
        {
            string s;
            s.push_back(tolower(str[i]));
            s.push_back(tolower(str[i + 1]));
            ++um[s];
        }
    }
}

int solution(string str1, string str2)
{
    unordered_map<string, int> um1;
    unordered_map<string, int> um2;
    CountSet(str1, um1);
    CountSet(str2, um2);

    if (um1.size() + um2.size() == 0)
    {
        return 65536;
    }


    int interSecNum = 0;
    for (auto it : um1)
    {
        string str = it.first;
        interSecNum += min(um1[str], um2[str]);
    }

    int unionNum = 0;
    for (auto it : um1)
    {
        string str = it.first;
        unionNum += um1[str];
    }
    for (auto it : um2)
    {
        string str = it.first;
        unionNum += um2[str];
    }
    unionNum -= interSecNum;

    interSecNum *= 65536;

    return interSecNum / unionNum;
}