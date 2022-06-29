#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    cin >> N;
    int cnt = 0;
    int Num = 665;
    string str;

    while (++Num)
    {
        str = to_string(Num);

        if (str.find("666") != -1)
            ++cnt;

        if (cnt == N)
        {
            cout << Num << "\n";
            break;
        }
    }

    return 0;
}