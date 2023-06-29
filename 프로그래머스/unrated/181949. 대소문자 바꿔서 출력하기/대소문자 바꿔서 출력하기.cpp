#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for (int i = 0; i < str.size(); i++)
		cout << (isupper(str[i]) ? (char)tolower(str[i]) : (char)toupper(str[i]));
    return 0;
}