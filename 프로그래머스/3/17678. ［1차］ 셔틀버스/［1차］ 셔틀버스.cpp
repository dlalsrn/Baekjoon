#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;

int ConvertTimeStoi(string s)
{
    int time = 0;
    int min, sec;
    char c;
    istringstream iss(s);

    iss >> min >> c >> sec;

    return min * 60 + sec;
}

string ConvertTimeItos(int t)
{
    string s = "";
    
    if (t / 60 < 10) s += '0';
    
    s += to_string(t / 60);
    s += ':';

    if (t % 60 < 10) s += '0';
    s += to_string(t % 60);

    return s;
}

string solution(int n, int t, int m, vector<string> timetable)
{
    string answer = "";
    vector<int> time;
    queue<int> wait;

    for (string s : timetable)
    {
        time.push_back(ConvertTimeStoi(s));
    }

    sort(time.begin(), time.end(), greater<>());

    int curTime = 540;
    for (int i = 0; i < n; ++i)
    {
        while (!time.empty() && time.back() <= curTime)
        {
            wait.push(time.back());
            time.pop_back();
        }

        int can = m;
        while (!wait.empty() && can > 1)
        {
            wait.pop();
            --can;
        }

        if (i == n - 1)
        {
            if (wait.empty())
            {
                answer = ConvertTimeItos(curTime);
            }
            else if (can == 1)
            {
                answer = ConvertTimeItos(wait.front() - 1);
            }

            break;
        }
        else
        {
            if (!wait.empty()) wait.pop();
        }

        curTime += t;
    }

    return answer;
}