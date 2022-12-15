#include <iostream>
#define NUM_COIN 7

using namespace std;

int coins[] = {1000, 500, 100, 50, 10, 5, 1};
//1원, 5원, 10원, 50원, 100원, 500원, 1000

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--)
    {
        int chage = 0;
        int answer = 0;
        cin >> chage;
        for(int i=0; i<NUM_COIN; i++)
        {
            if(chage>=coins[i]) //교환이 가능하다면
            {
                answer +=  chage/ coins[i];
                chage = chage%coins[i];
            }
        }
        cout << answer << "\n";

    }



    // for(int i=0; i<7; i++)
    // {
    //     cout << coins[i] << " ";
    // }


    return 0;
}   