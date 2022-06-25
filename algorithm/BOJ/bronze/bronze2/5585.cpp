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

    int cnt = 0;
    int Pay = 0;
    cin >> Pay;
    Pay = 1000 - Pay;
    // 주어진 값에서 1000원을 뺀 값을 기준으로

    if (Pay >= 500)
    {
        cnt++;
        Pay = Pay - 500;
    }
    // 제일 높은 거스름돈부터 빼주면서 계산해준다.

    if (Pay >= 100)
    {
        int temp = Pay / 100;
        cnt = cnt + temp;
        for (int i = 0; i < temp; i++)
            Pay = Pay - 100;
    }

    if (Pay >= 50)
    {
        int temp = Pay / 50;
        cnt = cnt + temp;
        for (int i = 0; i < temp; i++)
            Pay = Pay - 50;
    }

    if (Pay >= 10)
    {
        int temp = Pay / 10;
        cnt = cnt + temp;
        for (int i = 0; i < temp; i++)
            Pay = Pay - 10;
    }

    if (Pay >= 5)
    {
        int temp = Pay / 5;
        cnt = cnt + temp;
        for (int i = 0; i < temp; i++)
            Pay = Pay - 5;
    }
    if (Pay >= 1)
    {
        int temp = Pay / 1;
        cnt = cnt + temp;
        for (int i = 0; i < temp; i++)
            Pay = Pay - 1;
    }

    cout << cnt << "\n";

    return 0;
}