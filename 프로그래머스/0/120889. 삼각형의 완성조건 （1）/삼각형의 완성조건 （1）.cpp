#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> sides) {
    int answer;
    sort(sides.begin(), sides.end());
    return answer = sides[0] + sides[1] > sides[2] ? 1 : 2;
}