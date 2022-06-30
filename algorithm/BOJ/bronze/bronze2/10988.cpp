#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int check(string str)
{
    int len = str.length();
    bool check = false;

    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - (i + 1)])
        {
            check = true;
            break;
        }
        else
        {
            check = false;
        }
    }

    if (check == true)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    cout << check(str) << "\n";

    return 0;
}