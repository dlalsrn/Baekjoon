#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 1;
    char start = s[0];
    int cnt = 0;

    for (int i = 0; i < s.size() - 1; i++)
    {
        if (start == s[i]) cnt++;
        else cnt--;

        if (cnt == 0)
        {
            start = s[i + 1];
            answer++;
        }
    }

    return answer;
}