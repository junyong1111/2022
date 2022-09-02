#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt","r",stdin);
    int N =0;
    cin >> N ;
    vector<int>Arr1(N,0);
    vector<int>Arr2(N,0);

    for(int i=0; i<N; i++)
        cin >> Arr1[i];
    for(int i=0; i<N; i++)
        cin >> Arr2[i];

    if(Arr1 == Arr2){
        cout << 1 ;
        return 0;
    }
    
   
    int cnt = 0; 
    for(int i=0; i<N; i++){
        int Max = Arr1[0];   // 기준 값 정하기
        int Idx = 0;
        for(int j=1; j<N-i; j++){
            if(Max<=Arr1[j]){
                Max = Arr1[j];
                Idx = j;
            }
        }

         // 스왑이 일어나지 않은경우는 카운트를 세지 않으므로 예외 
            int temp = Arr1[N-i-1];
            Arr1[N-i-1] = Arr1[Idx];
            Arr1[Idx] = temp;

            if(Arr1 == Arr2){
                cout << 1 ;
                return 0;
            }    
        }  
    cout << 0 ; // 끝날 때 까지 타겟넘버가 안된다면 

    return 0;
}