#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    
    int number = 0;
    cin >> number ;
    vector<int>V(2002,0); //절댓값 처리

    for(int i=0; i<number; i++){
        int temp = 0;
        cin >> temp;
        if(temp <0){
            if(V[temp+2001]==0)
                V[temp+2001] = 1;
        }
        else{
            if(V[temp] ==0)
                V[temp] =1;
        }
    }
    for(int i=1001; i<=2000; i++){
        if(V[i] !=0){
            cout << i-2001 << " ";
        }
    }
    for(int i=0; i<=1000; i++){
        if(V[i] !=0){
            cout << i << " ";
        }
    }
   
    return 0;
} 