#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;
    vector<int> term(26, 0);
    int currentDay;
    istringstream iss(today);
    int year, month, day;
    char dot;

    iss >> year >> dot >> month >> dot >> day;
    currentDay = year * 28 * 12 + (month - 1) * 28 + day;

    for (int i = 0; i < terms.size(); i++)
    {
        char type;
        int m;
        istringstream iss(terms[i]);
        iss >> type >> m;
        term[type - 'A'] = m;
    }

    for (int i = 0; i < privacies.size(); i++)
    {
        istringstream iss(privacies[i]);
        char type;
        iss >> year >> dot >> month >> dot >> day >> type;
        int privacyDay = year * 28 * 12 + (month - 1) * 28 + day;

        if (privacyDay + term[type - 'A'] * 28 <= currentDay)
            answer.push_back(i + 1);
    }


    return answer;
}