#include <bits/stdc++.h>
using namespace std;

string solution(string s)
{
    string answer = "";

    bool newWord = true;

    for (char& c : s)
    {
        if (c == ' ')
        {
            newWord = true;
        }
        else
        {
            if (newWord)
            {
                c = toupper(c);
                newWord = false;
            }
            else
            {
                c = tolower(c);
            }
        }
    }

    return answer = s;
}