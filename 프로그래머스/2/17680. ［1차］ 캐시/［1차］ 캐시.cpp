#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    list<string> lst;

    for (int i = 0; i < cities.size(); ++i)
    {
        string curCity = cities[i];
        transform(curCity.begin(), curCity.end(), curCity.begin(), ::tolower);

        bool bExist = false;

        for (auto it = lst.begin(); it != lst.end(); ++it)
        {
            if (*it == curCity)
            {
                bExist = true;
                lst.push_back(curCity);
                lst.erase(it);
                break;
            }
        }

        if (bExist)
        {
            ++answer;
        }
        else
        {
            answer += 5;
            lst.push_back(curCity);

            if (lst.size() > cacheSize)
            {
                lst.pop_front();
            }
        }
    }

    return answer;
}