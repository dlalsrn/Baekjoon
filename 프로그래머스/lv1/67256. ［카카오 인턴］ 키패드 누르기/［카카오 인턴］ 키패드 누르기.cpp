#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers, string hand) {
    pair<int, int> left = {4, 1}, right = {4, 3};
    string answer = "";
    
    pair<int, int> point[10] = {{4, 2}, {1, 1}, {1, 2}, {1, 3}, {2, 1}, {2, 2}, {2, 3}, {3, 1}, {3, 2}, {3, 3}};
    
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer += "L";
            left = point[numbers[i]];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer += "R";
            right = point[numbers[i]];
        }
        else
        {
            int left_hand = abs(point[numbers[i]].first - left.first) + abs(point[numbers[i]].second - left.second);
            int right_hand = abs(point[numbers[i]].first - right.first) + abs(point[numbers[i]].second - right.second);
            if (left_hand < right_hand)
            {
                answer += "L";
                left = point[numbers[i]];
            }
            else if (left_hand > right_hand)
            {
                answer += "R";
                right = point[numbers[i]];
            }
            else
            {
                if (hand == "left")
                {
                    answer += "L";
                    left = point[numbers[i]];
                }
                else
                {
                    answer += "R";
                right = point[numbers[i]];
                }
            }
        }
    }
    
    return answer;
}