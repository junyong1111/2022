#include <iostream>
#define INF 2100000000

using namespace std;

int answer;
void checkArr(int *arr, int sz);

int Coins(int *coins,int chages, int sz);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        int chages = 0;
        cin >> chages;
        int size = 0 ;
        cin >> size;
        int *coins = new int[size];
        for(int i=size-1; i>=0; i--){
            cin >> coins[i] ;
        }
        int ans = Coins(coins, chages, size);
        cout << ans <<"\n";
        // checkArr(coins,size);
    }


    return 0;

}

void checkArr(int *arr, int sz){
    for(int i=0; i<sz; i++){
        cout << arr[i] << " ";
    }
    cout <<"\n";
}

int Coins(int *coins,int chages, int sz){
    if(chages<0)
        return INF;
    if(chages == 0)
        return 0;

    int min = INF;
    for(int i=0; i<sz; i++){
        int temp = Coins(coins, (chages - coins[i]), sz);
        if(temp<min){
            min = temp;
        }
    }
    return answer + min+1;
}