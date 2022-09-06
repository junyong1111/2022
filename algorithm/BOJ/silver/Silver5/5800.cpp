#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" , stdin);

    int number = 0;
    cin >> number;
    int clase_number = 1;
    while(number--){
        int size =0;
        cin >> size;
        string str= "Class";
        vector<int>V(size,0);
        for(int i=0; i<size; i++){
            cin >> V[i];
        }
        sort(V.rbegin(), V.rend());

        int max_gap =  V[0]-V[1];
        for(int i=1; i<size-1; i++){
            if(max_gap <V[i] - V[i+1]){
                max_gap = V[i] - V[i+1];
            }
        }

        cout <<  str << " " << clase_number++ <<"\n";
        cout << "Max " << V[0] << ", Min " << V[size-1] <<", Largest gap " << max_gap <<"\n";

        
    }

    
   
    return 0;
}