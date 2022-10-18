#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main(void)
{
    int k, sum = 0;
    stack <int> st;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int a;
        scanf("%d", &a);
        if (a != 0)
        {
            st.push(a);
            sum += a;
        }
        else
        {
            sum -= st.top();
            st.pop();
        }
    }
    printf("%d", sum);
    return 0;
}