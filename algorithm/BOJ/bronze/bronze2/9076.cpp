#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    int number = 0;
    cin >> number;

    vector<vector<int> >Score(number, vector<int>(5,0));

    for(int i=0; i<number; i++){
        for(int j=0; j<5; j++){
            cin >> Score[i][j];
        }
        sort(Score[i].begin(), Score[i].end());
        if(Score[i][3] - Score[i][1] >=4 ){
            cout << "KIN\n";
        }
        else{
            int sum = Score[i][1] + Score[i][2] + Score[i][3];
            cout << sum << "\n";
        }
        
        
    }
    return 0;
}