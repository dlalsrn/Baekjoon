#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <map>
#include <iostream>
using namespace std;

int changeSec(string s)
{
    int minute = stoi(s.substr(0, 2));
    int sec = stoi(s.substr(3, 2));
    return minute * 60 + sec;
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    map<int, int> in;
    map<int, int> out;
    map<int, int> totalInTime;

    int basicTime = fees[0]; // 기본 시간
    int basicCost = fees[1]; // 기본 요금
    int addTime = fees[2];   // 단위 시간
    int addCost = fees[3];   // 단위 요금

    for (string s : records)
    {
        istringstream iss(s);
        string time, ch;
        int car;

        iss >> time >> car >> ch;

        if (ch == "IN")
        {
            in[car] = changeSec(time);
            out[car] = changeSec("24:00");
        }
        else if (ch == "OUT")
        {
            int inTime = in[car];
            int outTime = changeSec(time);
            out[car] = outTime;
            int totalTime = outTime - inTime;
            totalInTime[car] += totalTime;
        }
    }

    for (auto [car, outTime] : out)
    {
        if (outTime == 24 * 60) // 출차가 안찍혀있으면
        {
            int inTime = in[car];
            int outTime = 24 * 60 - 1;
            int totalTime = outTime - inTime;
            totalInTime[car] += totalTime;
        }
    }

    for (auto [car, _] : in)
    {
        int totalTime = totalInTime[car];
        cout << car << ' ' << totalTime << '\n';
        int sum = basicCost + ceil((max(0, totalTime - basicTime)) / (float)addTime) * addCost;
        answer.push_back(sum);
    }

    return answer;
}