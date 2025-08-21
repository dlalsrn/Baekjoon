#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient)
{
    int answer = 0;
    string s = "";
    
    for (int& x : ingredient)
    {
        s += to_string(x);

        if (s.size() >= 4)
        {
            if (s.substr(s.size() - 4, 4) == "1231")
            {
                for (int i = 0; i < 4; i++)
                {
                    s.pop_back();
                }
                answer++;
            }
        }
    }

    return answer;
}