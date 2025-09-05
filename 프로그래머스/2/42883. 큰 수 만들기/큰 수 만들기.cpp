#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k)
{
    string answer = "";
    
    for (char c : number)
    {
        while (!answer.empty() && answer.back() < c && k > 0)
        {
            answer.pop_back();
            k--;
        }

        answer += c;
    }

    while (k > 0)
    {
        answer.pop_back();
        k--;
    }

    return answer;
}