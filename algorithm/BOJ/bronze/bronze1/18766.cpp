#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int test_case = 0;
    cin >> test_case;
    bool check = false;

    while(test_case--){
        int card = 0 ;
        cin >> card;
        vector<string>A_cards(card);
        vector<string>B_cards(card);
        for(int i=0; i<card; i++)
            cin >> A_cards[i];
        for(int i=0; i<card; i++)
            cin >> B_cards[i];
        sort(A_cards.begin(), A_cards.end());
        sort(B_cards.begin(), B_cards.end());


        for(int i=0; i<card; i++){
            if(A_cards[i] != B_cards[i])
            {   check = true;
                break;
                }

        }
        if(check==true){check = false; cout << "CHEATER\n";}
        else {cout << "NOT CHEATER\n";}
    }
    return 0;
}