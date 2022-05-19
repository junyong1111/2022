#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Num = 0;
    cin >> Num;
    vector<int>card(Num, 0);
    for(int i=0;i <Num; i++){
        cin >> card[i];
    }
    stable_sort(card.begin(), card.end());
    int check = 0;
    cin >> check;
    for(int i=0; i<check; i++){
        int search = 0 ;
        cin >> search;
        cout << upper_bound(card.begin(), card.end() , search) - lower_bound(card.begin(), card.end(), search) << " ";
        //upper_bound를 이용하면 값을 주어진 값을 기준으로 가장 큰 값의 idx를 알 수 있음
        //lower_bound를 이용하면 값을 기준으로 가장 작은 값의 idx를 알 수 있음
    }
    return 0;
}